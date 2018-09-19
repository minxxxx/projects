package com.router;

import com.core.decoders.Decoder;
import com.core.encoders.AcceptConnectionEncoder;
import com.core.encoders.BuySellEncoder;
import com.core.messages.AcceptConnection;
import com.core.messages.BuySell;
import com.core.messages.FIXMessage;
import com.core.messages.MessageTypes;
import io.netty.bootstrap.ServerBootstrap;
import io.netty.channel.*;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.nio.NioServerSocketChannel;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Router implements Runnable{

    private static HashMap<Integer, ChannelHandlerContext> routeTable = new HashMap<>();
    private String clientType;
    private final int port;

    private NioEventLoopGroup bossGroup;
    private NioEventLoopGroup workerGroup;

    public static void main (String [] args) {
        Router brokerServer = new Router(5000);
        Thread brokerServerThread = new Thread(brokerServer);
        brokerServerThread.start();

        Router marketServer = new Router(5001);
        Thread marketServerThread = new Thread(marketServer);
        marketServerThread.start();
    }

    public Router(int port) {
        this.port = port;
        clientType = port == 5000 ? "Broker" : "Market";
    }

    @Override
    public void run()
    {
        //accepts new connections as they arrive and pass them to worker for proccessing
        bossGroup = new NioEventLoopGroup();
        workerGroup = new NioEventLoopGroup();

        try {
            //determines how to server will process incoming connections
            ServerBootstrap bootstrap = new ServerBootstrap()
                    .group(bossGroup, workerGroup)
                    .channel(NioServerSocketChannel.class)
                    .childHandler(new ChannelInitializer(){
                        @Override
                        protected void initChannel(Channel channel) throws Exception
                        {
                            ChannelPipeline pipeline = channel.pipeline();

                            pipeline.addLast(new Decoder()); //outbound
                            pipeline.addLast(new AcceptConnectionEncoder()); //inbound
                            pipeline.addLast(new BuySellEncoder()); //inbound

                            pipeline.addLast(new ProcessingHandler());
                        }
                    }).option(ChannelOption.SO_REUSEADDR, true);


            //bind server to port and start listening for incoming connections
            ChannelFuture f = bootstrap.bind(port).sync();
            f.channel().closeFuture().sync();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            bossGroup.shutdownGracefully();
            workerGroup.shutdownGracefully();
        }
    }

    class ProcessingHandler extends ChannelInboundHandlerAdapter {



        @Override
        public void channelRead (ChannelHandlerContext ctx, Object msg) throws Exception {
            FIXMessage fixMessage = (FIXMessage) msg;
            if (fixMessage.getMessageType().equals(MessageTypes.ACCEPT_CONNECTION.toString())) {
                addToRouteTable(ctx, msg);
            }
            else if (fixMessage.getMessageType().equals(MessageTypes.BUY.toString()) ||
                    fixMessage.getMessageType().equals(MessageTypes.SELL.toString())) {
                BuySell buySellMessage = (BuySell) msg;
                System.out.println("A request is being processed...");
                Thread.sleep(1000);
                System.out.println(buySellMessage);
                try {
                    if (!routeTable.containsKey(buySellMessage.getMarketId())) {

                        throw new Exception("This market does not exist. ID " + buySellMessage.getMarketId());

                    }
                    else if (!buySellMessage.getMD5Message().equals(buySellMessage.getChecksum())) {
                        throw new Exception("The message data has been altered");
                    }
                    if (buySellMessage.getExecOrRejec().equals(MessageTypes.EXECUTE.toString()) ||
                            buySellMessage.getExecOrRejec().equals(MessageTypes.REJECT.toString())) {
                        //Market has responded and sends to broker
                        ChannelHandlerContext brokerCtx = getContextFromTable(buySellMessage.getId());
                        brokerCtx.writeAndFlush(buySellMessage);
                    }
                    else {
                        //Message goes from Broker to market
                        getContextFromTable(buySellMessage.getMarketId()).writeAndFlush(buySellMessage);
                    }
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                    buySellMessage.setExecOrRejec(MessageTypes.REJECT.toString());
                    buySellMessage.setNewChecksum();
                    ctx.writeAndFlush(buySellMessage);
                }
            }
            //showTable();
        }

        @Override
        public void handlerRemoved(ChannelHandlerContext ctx){
            System.out.println(clientType + " [" + getIdFromTable(ctx) + "] removed");
            try {
                routeTable.remove(getIdFromTable(ctx));
            } catch (Exception e) {
                System.out.println("[FAILED TO REMOVE CHANNEL FROM ROUTE TABLE]");
            }
        }

        @Override
        public void channelReadComplete(ChannelHandlerContext ctx) throws Exception {
            //showTable();
        }
    }

    private ChannelHandlerContext getContextFromTable(Integer key) {
        return routeTable.get(key);
    }


    private Integer getIdFromTable(ChannelHandlerContext ctx) {
        int id = 0;
        for (HashMap.Entry<Integer, ChannelHandlerContext> entry : routeTable.entrySet()) {
            if (entry.getValue() == ctx) {
                id = entry.getKey();
            }
        }
        return id;
    }

    private void showTable() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String input = in.readLine();
        if (input.equals("show table")) {
            for (HashMap.Entry<Integer, ChannelHandlerContext> entry : routeTable.entrySet()) {
                System.out.println("[" + entry.getKey() + "] - " + isMarketOrBroker(entry.getKey().toString()));
            }
        }
    }

    public String isMarketOrBroker(String id) {
        if (id.substring(5).equals("0")) {
            return "Market";
        }
        return "Broker";
    }

    private void addToRouteTable(ChannelHandlerContext ctx, Object msg) {
        AcceptConnection acceptConnection = (AcceptConnection) msg;
        String id = ctx.channel().remoteAddress().toString().substring(11);
        String tempSub = clientType.equals("Market") ? "0" : "1";
        id = id.concat(tempSub);
        acceptConnection.setId(Integer.parseInt(id));
        acceptConnection.setNewChecksum();
        System.out.println("Accepted connection from " + ctx.channel().remoteAddress() + "\nSet ID to " + id);
        ctx.writeAndFlush(acceptConnection);
        routeTable.put(Integer.valueOf(id), ctx);
    }
}

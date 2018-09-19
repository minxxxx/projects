package com.core;

import com.core.decoders.Decoder;
import com.core.encoders.AcceptConnectionEncoder;
import com.core.encoders.BuySellEncoder;
import com.core.messages.AcceptConnection;
import com.core.messages.BuySell;
import com.core.messages.FIXMessage;
import com.core.messages.MessageTypes;
import io.netty.bootstrap.Bootstrap;
import io.netty.channel.*;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioSocketChannel;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Client implements Runnable{

    private EventLoopGroup workerGroup;
    private String clientType;
    private int port;
    private int id;
    private String host;

    public Client(String host, int port) {
        this.port = port;
        this.host = host;
        switch (port) {
            case 5000:
                clientType = "Broker";
                break;
            case 5001:
                clientType = "Market";
                break;
        }
    }

    public static void inputHandler(Client client) {
        System.out.println("Handleinput");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        while (true) {
            input = null;
            try {
                input = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (input.toLowerCase().equals("exit")) {
                client.workerGroup.shutdownGracefully();
                break;
            }
        }
    }

    @Override
    public void run() {
        workerGroup = new NioEventLoopGroup();
        try {
            Bootstrap server = new Bootstrap();
            server.group(workerGroup)
                    .channel(NioSocketChannel.class)
                    .handler(new ChannelInitializer<SocketChannel>() {
                        @Override
                        protected void initChannel(SocketChannel socketChannel) throws Exception {
                            ChannelPipeline pipeline = socketChannel.pipeline();

                            pipeline.addLast(new Decoder()); //outbound
                            pipeline.addLast(new AcceptConnectionEncoder()); //inbound
                            pipeline.addLast(new BuySellEncoder()); //inbound

                            pipeline.addLast(new ClientHandler());
                        }
                    });
            ChannelFuture f = server.connect(this.host, this.port).sync();
            f.channel().closeFuture().sync();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            workerGroup.shutdownGracefully();
        }
    }

    class ClientHandler extends ChannelInboundHandlerAdapter {
        //Handles all decoded incoming strings from server
        @Override
        public void channelActive(ChannelHandlerContext ctx) {
            System.out.println(clientType + " is connecting..." + ctx.channel().remoteAddress());
            AcceptConnection msg = new AcceptConnection(MessageTypes.ACCEPT_CONNECTION.toString(), 0 , 0);

            ctx.writeAndFlush(msg);
        }

        @Override
        public void channelRead(ChannelHandlerContext ctx, Object msg) {
            //System.out.println("[SERVER] - " + msg)
            FIXMessage fixMessage = (FIXMessage) msg;
            if (fixMessage.getMessageType().equals(MessageTypes.ACCEPT_CONNECTION.toString())) {
                AcceptConnection acceptConnection = (AcceptConnection) msg;
                id = acceptConnection.getId();
                System.out.println("Server assigned ID: " + acceptConnection.getId());
            }
            else if (fixMessage.getMessageType().equals(MessageTypes.BUY.toString()) ||
                    fixMessage.getMessageType().equals(MessageTypes.SELL.toString())) {
                BuySell buySell = (BuySell) msg;
                try {
                    if (!buySell.getMD5Message().equals(buySell.getChecksum())) {
                        throw new Exception("Checksum is not valid");
                    }
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                    return;
                }

                if ((buySell.getExecOrRejec().equals(MessageTypes.EXECUTE.toString()) ||
                        buySell.getExecOrRejec().equals(MessageTypes.REJECT.toString())) && clientType.equals("Broker"))  {
                    System.out.println("The market has responded with: " + buySell.getExecOrRejec());
                    System.out.println("Requested: " + buySell.getQuantity() + "x " + buySell.getInstrument() +
                            " for R " + buySell.getPrice() );

                    return;
                }

                System.out.println(buySell);
                if (buySell.getMessageType().equals(MessageTypes.SELL.toString())) {
                    handleSellRequest(ctx, buySell);
                    return;
                } else if (buySell.getMessageType().equals(MessageTypes.BUY.toString())) {
                    handleBuyRequest(ctx, buySell);
                    return;
                }
            }
        }

        private void channelWrite(ChannelHandlerContext ctx) {
            try {
                String input = getClientText();
                if (input.length() == 0) {
                    throw new Exception("Input is empty");
                }
                else if (clientType.equals("Broker")) {
                    BuySell msg = convertToBuySell(input);
                    ctx.writeAndFlush(msg);
                    System.out.println("Sending request to router...");
                    Thread.sleep(1000);
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
                channelWrite(ctx);
            }
        }

        @Override
        public void channelReadComplete(ChannelHandlerContext ctx) {
            if (clientType.equals("Broker"))
                channelWrite(ctx);
        }
    }

    private void handleBuyRequest(ChannelHandlerContext ctx, BuySell buySell) {
        if (buySell.getPrice() > buySell.getQuantity()) {
            buySell.setExecOrRejec(MessageTypes.REJECT.toString());
            System.out.println("Buy request for " + buySell.getQuantity() + "x " + buySell.getInstrument() +
                    " has been REJECTED");

        }
        else {
            buySell.setExecOrRejec(MessageTypes.EXECUTE.toString());
            System.out.println("Buy request has been EXECUTED");
            System.out.println("Bought " + buySell.getQuantity() + "x " + buySell.getInstrument() + " for R " +
                    buySell.getPrice());
        }
        buySell.setNewChecksum();
        ctx.writeAndFlush(buySell);

    }

    private void handleSellRequest(ChannelHandlerContext ctx, BuySell buySell) {
        if (buySell.getQuantity() > 1000 && buySell.getPrice() > 1000)  {
            buySell.setExecOrRejec(MessageTypes.REJECT.toString());
            System.out.println("Sell request for " + buySell.getQuantity() + "x " + buySell.getInstrument() +
                    " has been REJECTED");
        }
        else {
            buySell.setExecOrRejec(MessageTypes.EXECUTE.toString());
            System.out.println("Sell request has been EXECUTED");
            System.out.println("Sold " + buySell.getQuantity() + " " + buySell.getInstrument() + " for R " +
                    buySell.getPrice());
        }
        buySell.setNewChecksum();
        ctx.writeAndFlush(buySell);
    }

    private String getClientText() throws Exception{
        System.out.println("Enter a request -> [sell || buy] [market id] [instrument] [quantity] [price] ");
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        return in.readLine();
    }

    private BuySell convertToBuySell(String brokerInput) throws Exception {
        BuySell buySellMessage = new BuySell();
        String [] buySellAtt = brokerInput.split("\\s+");
        if (buySellAtt[0].equalsIgnoreCase("buy")) {
            buySellMessage.setMessageType(MessageTypes.BUY.toString());
        } else if (buySellAtt[0].equalsIgnoreCase("sell")) {
            buySellMessage.setMessageType(MessageTypes.SELL.toString());
        } else {
            throw new Exception("Invalid input");
        }
        buySellMessage.setId(id);
        buySellMessage.setExecOrRejec("-");
        buySellMessage.setMarketId(Integer.valueOf(buySellAtt[1]));
        buySellMessage.setInstrument(buySellAtt[2]);
        buySellMessage.setQuantity(Integer.valueOf(buySellAtt[3]));
        buySellMessage.setPrice(Integer.valueOf(buySellAtt[4]));
        buySellMessage.setNewChecksum();
        System.out.println(buySellMessage.toString());
        return buySellMessage;
    }

}

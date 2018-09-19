package com.core.encoders;

import com.core.messages.BuySell;
import com.core.messages.MessageTypes;
import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.handler.codec.MessageToByteEncoder;

import java.nio.charset.Charset;

public class BuySellEncoder extends MessageToByteEncoder <BuySell> {

    private Charset cs = Charset.forName("UTF-8");

    @Override
    protected void encode(ChannelHandlerContext ctx, BuySell msg, ByteBuf out) throws Exception {
        out.writeInt(msg.getTypeLength());
        out.writeCharSequence(msg.getMessageType(), cs);
        if (msg.getMessageType().equals(MessageTypes.BUY.toString()) ||
                msg.getMessageType().equals(MessageTypes.SELL.toString())) {
            out.writeInt(msg.getId());
            out.writeInt(msg.getExecOrRejecLength());
            out.writeCharSequence(msg.getExecOrRejec(), cs);
            out.writeInt(msg.getMarketId());
            out.writeInt(msg.getInstrumentLength());
            out.writeCharSequence(msg.getInstrument(), cs);
            out.writeInt(msg.getQuantity());
            out.writeInt(msg.getPrice());
            out.writeInt(msg.getChecksumLength());
            out.writeCharSequence(msg.getChecksum(), cs);
        }
    }
}

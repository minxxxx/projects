package com.core.encoders;

import com.core.messages.AcceptConnection;
import com.core.messages.MessageTypes;
import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.handler.codec.MessageToByteEncoder;

import java.nio.charset.Charset;

public class AcceptConnectionEncoder extends MessageToByteEncoder<AcceptConnection> {
    //Encodes Strings to Bytes to send to server
    private final Charset cs = Charset.forName("UTF-8");

    @Override
    protected void encode(ChannelHandlerContext ctx, AcceptConnection msg, ByteBuf out) throws Exception {
        out.writeInt(msg.getTypeLength());
        out.writeCharSequence(msg.getMessageType(), cs);
        if (msg.getMessageType().equals(MessageTypes.ACCEPT_CONNECTION.toString())) {
            out.writeInt(msg.getId());
            out.writeInt(msg.getChecksumLength());
            out.writeCharSequence(msg.getChecksum(), cs);
        }
    }
}
package com.core.messages;

import com.core.MD5;

public class AcceptConnection extends FIXMessage {
    private int id;

    public AcceptConnection(String messageType, int marketId, int id) {
        super(messageType, marketId);
        this.id = id;
        setNewChecksum();
    }

    public AcceptConnection() {}

    public int getId() {
        return id;
    }

    public void setId(int messageId) {
        this.id = messageId;
    }

    public void setNewChecksum() {
        setChecksum(MD5.createMD5(String.valueOf(id)));
    }

    @Override
    public String toString() {
        String ret = "ID = " + id +
                     " | Market ID = " + getMarketId() +
                     " | MESSAGE TYPE = " + getMessageType() +
                     " | CHECKSUM = " + getChecksum();
        return ret;
    }
}
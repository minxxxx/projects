package com.core.messages;

public class FIXMessage {
    private int     typeLength;
    private int     marketId;
    private int     checksumLength;
    private String  checksum;
    private String  messageType;

    public FIXMessage() {}

    public FIXMessage(String messageType, int marketId) {
        this.messageType = messageType;
        this.typeLength = messageType.length();
        this.marketId = marketId;
    }

    public String getMessageType() {
        return messageType;
    }

    public void setMessageType(String messageType) {
        this.messageType = messageType;
        this.typeLength = messageType.length();
    }

    public String getChecksum() {
        return this.checksum;
    }

    public void setChecksum(String checksum) {
        this.checksum = checksum;
        this.checksumLength = checksum.length();
    }

    public int getMarketId() {
        return marketId;
    }

    public void setMarketId(int marketId) {
        this.marketId = marketId;
    }

    public int getTypeLength() {
        return typeLength;
    }

    public int getChecksumLength() {
        return checksumLength;
    }
}

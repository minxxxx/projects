package com.core.messages;

import com.core.MD5;

public class BuySell extends FIXMessage {
    private String instrument;
    private int quantity;
    private int price;
    private int id;
    private String execOrRejec;
    private int execOrRejecLength;
    private int instrumentLength;


    public BuySell(String messageType, String execOrRejec, int marketId, int id, String instrument, int quantity) {
        super(messageType, marketId);
        this.execOrRejec = execOrRejec;
        this.instrument = instrument;
        this.quantity = quantity;
        this.id = id;
        this.execOrRejecLength = execOrRejec.length();
        this.instrumentLength = instrument.length();
        setNewChecksum();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getExecOrRejecLength() {
        return execOrRejecLength;
    }
    
    public BuySell() {}

    public String getExecOrRejec() {
        return execOrRejec;
    }

    public void setExecOrRejec(String execOrRejec) {
        this.execOrRejec = execOrRejec;
        this.execOrRejecLength = execOrRejec.length();
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public String getInstrument() {
        return instrument;
    }

    public void setInstrument(String instrument) {
        this.instrument = instrument;
        this.instrumentLength = instrument.length();
    }

    public int getInstrumentLength() {
        return instrumentLength;
    }

    public void setInstrumentLength(int instrumentLength) {
        this.instrumentLength = instrumentLength;
    }

    public String getMD5Message() {
        return (MD5.createMD5(String.valueOf(id).
                concat(execOrRejec).
                concat(instrument).
                concat(String.valueOf(quantity))));
    }

    public void setNewChecksum() {
        setChecksum(getMD5Message());
    }

    @Override
    public String toString () {
        String ret = "ID = " + id +
                     " | MARKET ID = " + getMarketId() +
                     " | MESSAGE TYPE = " + getMessageType() +
                     " | MESSAGE ACTION = " + getExecOrRejec() +
                     " | INSTRUMENT = " + getInstrument() +
                     " | QUANTITY = " + getQuantity() +
                     " | PRICE = " + getPrice() +
                     " | CHECKSUM = " + getChecksum();
        return ret;
    }
}

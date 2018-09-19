package com.market;

import com.core.Client;

public class Market {

    public static void main(String[] args) {
        Client market = new Client("localhost", 5001);

        market.run();
    }

}

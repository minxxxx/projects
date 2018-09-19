package com.broker;

import com.core.Client;

public class Broker
{
    public static void main (String []args) throws Exception {
        Client broker = new Client("localhost", 5000);

        broker.run();
    }

}

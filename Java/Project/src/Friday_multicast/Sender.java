package Friday_multicast;

import java.io.BufferedWriter;

public class Sender implements Runnable {
    BufferedWriter bw;

    Sender(BufferedWriter bw) {
        this.bw = bw;
    }

    @Override
    public void run() {
        String msg = "";


    }
}

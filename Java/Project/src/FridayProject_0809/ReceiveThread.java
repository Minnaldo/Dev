package FridayProject_0809;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.net.Socket;

public class ReceiveThread extends Thread {
    Socket socket;
    BufferedReader br;
    BufferedWriter bw;

    @Override
    public void run() {
        String receive;
        try {
            String msg = null;
            while ((msg = br.readLine()) != null) {
                System.out.println(msg);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    ReceiveThread(Socket socket){
        this.socket = socket;
    }

    ReceiveThread(BufferedReader br) {
        this.br = br;
    }

    ReceiveThread(Socket socket, BufferedReader br) {
        this.socket = socket;
        this.br = br;
    }
}

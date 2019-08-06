package practice;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ThreadServer {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(9999);
            while (true) {
                Socket client = ss.accept();

                new Thread(new Runnable() {
                    @Override
                    public void run() {

                    }
                })
            }
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}

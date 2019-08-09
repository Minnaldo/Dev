package Friday_multicast;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(9999);
            while (true) {
                Socket client = ss.accept();
                System.out.println(client.getInetAddress().getHostAddress()+"가 접속하였습니다.");
                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
                BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));

                ServerThread.bwPool.add(bw);
                new Thread(new ServerThread(br)).start();

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

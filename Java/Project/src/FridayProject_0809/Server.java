package FridayProject_0809;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server implements Runnable{

    BufferedReader br;
    static ArrayList<BufferedWriter> bwPool = new ArrayList<>();
    public String msg = null;

    private void go() throws IOException {
        ServerSocket ss = new ServerSocket(9999);
        while (true) {
            Socket client = ss.accept();

            bwPool.add(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())));

        }
    }

    public static void main(String[] args) {
        try {
            new Server().go();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        String msg = null;
        // 메시지가 정상적으로 받아졌다면
        try {
            while((msg = br.readLine()) != null){
                for(BufferedWriter bw : bwPool){
                    bw.write(msg + "\n");
                    bw.flush();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

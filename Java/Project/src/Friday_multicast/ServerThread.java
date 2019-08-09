package Friday_multicast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;


public class ServerThread implements Runnable {

    // Server 클래스에서 접근해  BufferedReader를 추가한다.
    static ArrayList<BufferedWriter> bwPool = new ArrayList<>();
    BufferedReader br;

    ServerThread(BufferedReader br) {
        this.br = br;
    }

    @Override
    public void run() {
        String msg = null;
        try {
            while ((msg = br.readLine()) != null) {
                for (BufferedWriter bw : bwPool) {
                    bw.write(msg + "\n");
                    bw.flush();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

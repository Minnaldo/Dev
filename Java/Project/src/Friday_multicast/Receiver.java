package Friday_multicast;

import java.io.BufferedReader;
import java.io.IOException;

public class Receiver implements Runnable {
    BufferedReader br;

    Receiver(BufferedReader br) {
        this.br = br;
    }

    @Override
    public void run() {

        String msg = "";
        try {
            while (((msg = br.readLine()) != null)) {
                System.out.println("전송받은 메시지 : "+msg);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}

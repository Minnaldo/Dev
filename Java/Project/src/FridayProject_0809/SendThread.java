package FridayProject_0809;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class SendThread extends Thread {

    Socket socket;
    BufferedWriter bw;
    Scanner sc = new Scanner(System.in);

    SendThread(Socket socket){
        this.socket = socket;
    }

    SendThread(Socket socket, BufferedWriter bw) {
        this.socket = socket;
        this.bw = bw;
    }

    @Override
    public void run() {
        try {
            while (true) {
//                bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
                PrintWriter pw = new PrintWriter(socket.getOutputStream());
                pw.write(sc.nextLine());
                pw.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

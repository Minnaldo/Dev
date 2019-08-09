package FridayProject_0809;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    private void go() throws IOException {
        Socket socket = new Socket("localhost", 9999);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        // welcome message
        System.out.println(br.readLine());
        bw.write("반갑습니다.");
        bw.flush();
        Scanner sc = new Scanner(System.in);
        while(true){
            bw.write(sc.nextLine()+"\n");
            bw.flush();
        }
    }

    public static void main(String[] args) {

        try {
            Socket client = new Socket("192.168.24.132",7777);
            new SendThread(client).start();
            new ReceiveThread(client).start();
        } catch (IOException e) {
            e.printStackTrace();
        }
        //        try {
////            new Client().go();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
    }
}

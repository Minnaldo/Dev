package chap08;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class ClientTest {
    public static void main(String[] args) {
        BufferedWriter bw = null;
        BufferedReader br = null;
        Socket socket = null;
        Scanner sc = null;
        try {
            socket = new Socket("127.0.0.1", 9999);
            bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            br = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            sc = new Scanner(System.in);
            bw.write(sc.nextLine());
            bw.flush();

            System.out.println("echo : " + br.readLine());

            br.close();
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
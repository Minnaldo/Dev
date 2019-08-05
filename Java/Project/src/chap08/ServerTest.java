package chap08;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerTest {
    public static void main(String[] args) {
        // 9999 포트를 서버소켓으로 열어둔다
        BufferedReader br = null;
        BufferedWriter bw = null;
        ServerSocket ss = null;

        try {
            ss = new ServerSocket(9999);
            Socket client = ss.accept();
            System.out.println("[Server Ready]");
            br = new BufferedReader(new InputStreamReader(client.getInputStream()));
//            bw = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));

            String str = br.readLine();
            System.out.println("Client 로부터 날라온 문자열 \t" + str);
//            System.out.println(br.readLine());
//            bw.write();
//            bw.flush();

//            bw.close();
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


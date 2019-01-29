import java.io.*;
import java.net.*;

public class File_Client {

    private static final int PORT = 9999;
    private static final String addr = "127.0.0.1";
    private static final int snd_BUF = 1024;
    private static final int rcv_BUF = 1024;
    private static final String file_route = "./receiving";

    public static void main(String[] args) {
        try {
            // 소켓 선언과 연결
            Socket client_Socket = new Socket();
            InetSocketAddress ipep = new InetSocketAddress(addr, PORT);
            client_Socket.connect(ipep);

            if (!client_Socket.isConnected()) {
                System.out.println("Connect Error!");
                client_Socket.close();
                return;
            } else {
                System.out.println("Connected to Server");
            }

            try {
                OutputStream sender = client_Socket.getOutputStream();
                InputStream receiver = client_Socket.getInputStream();

                byte[] snd_data = new byte[snd_BUF];
                byte[] rcv_data = new byte[rcv_BUF];

                receiver.read(rcv_data, 0, rcv_data.length);

                // header = the variable that save file size
                String header = new String(rcv_data, 0, 10); // 10byte만큼 읽어온다
                header = "0000000000".substring(0,10-header.length())+header;
                System.out.println("File size : " + header);
                System.out.println(Integer.parseInt(header));

                // FileOutputStream fos = new FileOutputStream(/* File name */ file_route +
                // "/client_test");


                // while (file_size > 0) {
                // int tmp = receiver.read(rcv_data, 0, rcv_data.length);
                // fos.write(rcv_data, 0, rcv_data.length);
                // file_size -= tmp;
                // }
                // fos.close(); // 파일 버퍼 닫기

                receiver.read(rcv_data, 0, rcv_data.length);

                System.out.println(new String(rcv_data)); // 종료 메세지 출력

                client_Socket.close(); // 소켓 닫기

            } catch (Exception e) {
                e.printStackTrace();
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}
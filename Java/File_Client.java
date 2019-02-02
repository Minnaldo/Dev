import java.io.*;
import java.net.*;
import java.util.Arrays;

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
                OutputStream sender = client_Socket.getOutputStream();  // 송신 스트림 객체 생성
                InputStream receiver = client_Socket.getInputStream();  // 수신 스트림 객체 생성

                byte[] snd_data = new byte[snd_BUF];
                byte[] rcv_data = new byte[rcv_BUF];

                receiver.read(rcv_data, 0, rcv_data.length);

                // header = the variable that save file size
                String header = new String(rcv_data, 0, 10); // 10byte만큼 읽어와서 바로 String 객체 header에 할당
                header = "0000000000".substring(0, 10 - header.length()) + header;
                int file_size = Integer.parseInt(header);
                System.out.print("File size : " + file_size);

                Arrays.fill(rcv_data, (byte) 0);
                FileOutputStream fos = new FileOutputStream(/* File name */ file_route + "/client_test.txt");

                while (file_size > 0) {
                    int tmp = receiver.read(rcv_data, 0, rcv_data.length);
                    fos.write(rcv_data, 0, rcv_data.length);
                    file_size -= tmp;
                }

                fos.close(); // 파일 버퍼 닫기

                Arrays.fill(rcv_data, (byte) 0);
                receiver.read(rcv_data, 0, rcv_data.length);
                System.out.println(new String(rcv_data)); // 종료 메세지 출력

                receiver.close(); // 수신 스트림 닫기
            } catch (Exception e) {
                e.printStackTrace();
            }
            client_Socket.close(); // 소켓 닫기
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}
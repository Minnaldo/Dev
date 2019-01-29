import java.net.*;
import java.nio.ByteBuffer;
import java.util.Arrays;

import java.io.*;

public class File_Server {

    static final int PORT = 9999;
    private static final int snd_BUF = 1024;
    private static final int rcv_BUF = 1024;

    public static void main(String[] args) {

        try {
            ServerSocket server_Socket = new ServerSocket();
            InetSocketAddress ipep = new InetSocketAddress(PORT);
            server_Socket.bind(ipep);

            System.out.println("Initialize complete");

            Socket client_Socket = server_Socket.accept();

            if (!client_Socket.isConnected()) {
                System.out.println("Connect Error!");
                server_Socket.close();
                return;
            }

            System.out.println(client_Socket.getInetAddress() + " : " + client_Socket.getPort());
            System.out.println("Client Connected");

            try {
                OutputStream sender = client_Socket.getOutputStream(); // Client소켓에 입력함
                InputStream receiver = client_Socket.getInputStream(); // Client소켓으로부터 입력받음

                File file = new File(/* 파일 경로 입력 */"./sending/test_Text.txt");
                FileInputStream fio = new FileInputStream(file);
                // TODO  what is the valueOf Function?
                String file_size = String.valueOf(file.length());   // get file size
                System.out.println("File size 1111 ::::"+file_size);
                String header = "0000000000".substring(0,10-file_size.length())+file_size;
                int tmpSize = Integer.parseInt(file_size);

                // byte[] data = Integer.toString(file_size).getBytes();
                // byte[] data = ByteBuffer.allocate(4).putInt(file_size).array(); // int to
                // byte array
                sender.write(header.getBytes()); // send the file size

                System.out.println("file Size : " + tmpSize);
                System.out.println(tmpSize); // 파일 크기 출력

                // TODO  find it that Arrays.fill();
                // Arrays.fill(data, (byte) 0); // byte 배열 data의 모든 원소 0초기화
                // while (tmpSize > 0) {
                // // 실제 파일 전송, File io stream 이용 해 파일 읽고 sender로 보내기
                // int tmp = fio.read(data, 0, data.length);
                // sender.write(data, 0, data.length);
                // tmpSize -= tmp;
                // }
                fio.close(); // 파일 버퍼 닫기

                String fin_message = "finished";
                sender.write(fin_message.getBytes()); // 종료 메세지 전송

                sender.close(); // 소켓 닫기
            } catch (Exception e) {
                e.printStackTrace();
            }
            server_Socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}
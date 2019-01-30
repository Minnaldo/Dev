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
            server_Socket.bind(ipep);   // 서버 소켓 바인드 (Initialize)
            System.out.println("Initialize complete");

            // 클라이언트 소켓이 접속하면 서버 소켓과 연결
            Socket client_Socket = server_Socket.accept();
            // 소켓이 연결이 안되면 에러메시지 출력후 종료, Tyime Out을 집어넣으면 좋을 듯
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

                // valueOf() ==> file.length()를 String형으로 변환하여 반환
                String file_size = String.valueOf(file.length()); // get file size

                // 읽어온 파일의 크기를 byte단위로 저장
                String header = "0000000000".substring(0, 10 - file_size.length()) + file_size;
                int tmpSize = Integer.parseInt(file_size);

                byte[] data = new byte[snd_BUF];
                sender.write(header.getBytes()); // send the file size

                // 파일 크기 출력
                System.out.println("file Size : " + tmpSize);
                // System.out.println(tmpSize);

                // TODO find it that Arrays.fill();
                Arrays.fill(data, (byte) 0); // byte 배열 data의 모든 원소 0초기화
                while (tmpSize > 0) {
                    // 실제 파일 전송, File io stream 이용 해 파일 읽고 sender로 보내기
                    int tmp = fio.read(data, 0, data.length);
                    sender.write(data, 0, data.length);
                    tmpSize -= tmp;
                }
                sender.flush();
                fio.close(); // 파일 버퍼 닫기

                String fin_message = "transfer finished";
                sender.write(fin_message.getBytes()); // 종료 메세지 전송
                System.out.println(fin_message);

                sender.close(); // 전송 스트림 닫기
            } catch (Exception e) {
                e.printStackTrace();
            }
            server_Socket.close();  // 서버 소켓 닫기
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}
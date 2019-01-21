import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.InetSocketAddress;

/**
 *  * 전송시 OutputStream /수신시 InputStream 을 이용하여 송수신
 *  * 수신 read(byte, offset, length); / 송신 write(byte, offset, length); 사용
 *  * 소켓 통신을 더욱 OOP스럽게 하려면, 데이터 헤더 클래스를 이용
 */

public class Client {
    public static void main(String[] args) {
        int PORT = 9999; // 서버 port
        String addr = "alban.ddns.net"; // 서버 address

        // 자동 close, 클라이언트 소켓 선언
        try (Socket client_Socket = new Socket()) {
            // 클라이언트 소켓 초기화
            InetSocketAddress ipep = new InetSocketAddress(addr, PORT);
            // 접속 ( Connect )
            client_Socket.connect(ipep);

            // sender, receiver stream 받아오기
            try (OutputStream sender = client_Socket.getOutputStream();
                    InputStream receiver = client_Socket.getInputStream();) {
                // 서버로부터 데이터 받기
                byte[] data = new byte[100];
                receiver.read(data, 0, 100);    // byte, offset, length

                // 수신 메세지 출력
                String msg = new String(data);
                String out = String.format("receive - %s", msg);    // ? what is 'String.format();'
                System.out.println(out);

                // 서버로 데이터 보내기
                // 메세지 선언 --> 메시지를 바이트 배열에 할당 --> 전송(write)
                msg = "OK";
                data = msg.getBytes();
                sender.write(data, 0, data.length);
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}
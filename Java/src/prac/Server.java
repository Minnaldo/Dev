import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *  * 전송시 OutputStream /수신시 InputStream 을 이용하여 송수신
 *  * 소켓 통신을 더욱 OOP스럽게 하려면, 데이터 헤더 클래스를 이용
 */

public class Server {
    public static void main(String[] args) {

        int PORT = 9999;

        // 자동 close, 서버 소켓 선언
        try (ServerSocket server_Socket = new ServerSocket()) {
            // 서버 소켓 초기화
            InetSocketAddress ipep = new InetSocketAddress(PORT);
            server_Socket.bind(ipep); // InetSocketAddress 객체와 바인드

            System.out.println("Initialize coplete");

            // Server listenning, wait for accept
            Socket client_Socket = server_Socket.accept();
            System.out.println(client_Socket.getInetAddress()+" : " + client_Socket.getPort());
            System.out.println("Connection");   // print connection message, when client accept

            // send, receiver stream 받아오기
            try (OutputStream sender = client_Socket.getOutputStream();
                    InputStream receiver = client_Socket.getInputStream();) {
                // 클라이언트로 메시지 보내기
                String msg = "Socket Transfer Test";
                byte[] data = msg.getBytes();   // 메시지 길이만큼 byte배열 생성
                sender.write(data, 0, data.length); // byte, offset, length

                data = new byte[2];
                receiver.read(data, 0, data.length);// byte, offset, length

                msg = new String(data);
                String out = String.format("recieve - %s", msg);    // ? what is 'String.format();'
                System.out.println(out);
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}
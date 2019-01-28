import java.net.*;
import java.io.*;

public class File_Server{

    static final int PORT = 9999;

    public static void main(String[] args) {

        ServerSocket server_Socket = new ServerSocket();
        try{
            InetSocketAddress ipep = new InetSocketAddress(PORT);
            server_Socket.bind(ipep);

            System.out.println("Initialize complete");

            Socket client_Socket = server_Socket.accept();
            System.out.println(client_Socket.getInetAddress()+ " : "+client_Socket.getPort());
            System.out.println("Client Connected");

            try{
                OutputStream sender = client_Socket.getOutputStream();  // Client소켓에 입력함
                InputStream receiver = client_Socket.getInputStream();  // Client소켓으로부터 입력받음

                File file = new File(/* 파일 경로 입력 */);
                int file_size = file.length();
                int tmpSize = file_size;

                byte[] data = file_size.toString().getBytes();
                sender.write(data, 0, data.length); // 파일 크기 전송

                while(){
                    // 실제 파일 전송, File io stream 이용 해 파일 읽고 sender로 보내기
                }
            }
        }
        catch(Throwable e)
        {
            e.printStackTrece();
        }
    }
}
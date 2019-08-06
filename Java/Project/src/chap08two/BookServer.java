package chap08two;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;


// connect를 하고 나서는, 서버와 클라이언트는 반대로 열어야 한다.
// Client : ouput on, input on 이면, Server : input on , ouput on 순서로 스트림을 열어야 한다.
public class BookServer {
    private ArrayList<Socket> clients;  // 클라이언트를 관리할 객체 만들 수 도 있다.
    private ServerSocket ssock;

    public void BookServer() throws IOException {
        ssock = new ServerSocket(8080);
        clients = new ArrayList<>();
    }

    void print(List<Book> list) {
        for (Book b : list) {
            System.out.println(b.toString());
        }
    }

    void go() throws IOException, ClassNotFoundException {
        ssock = new ServerSocket(8080);
        // 서버는 계속 듣고 있다가, 클라이언트가 접속을 해오면 스레드를 새로 생성해서 소켓 객체를 넘겨준다
        while (true) {
            System.out.println("[Server]  Waiting");
            Socket client = ssock.accept();
            // 클라이언트가 서버에 접속하면, clients라는 소켓 관리 객체에 집어 넣고
            // 이를 thread에서 접속을 종료할 때 삭제한다.
            System.out.println(client.getInetAddress().getHostAddress() + " 님이 접속 하셨습니다.");
            clients.add(client);    // 클라이언트 풀에 클라이언트 객체 넣기
            System.out.println("현재 접속중인 client 는 " + clients.size() + " 입니다.");
            new ClientThread(client).start();
        }

    }

    public static void main(String[] args) {
        try {
            new BookServer().go();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println(e.toString());
        }
    }

    private class ClientThread extends Thread {
        private Socket accept;
        private BufferedInputStream bis;

        ClientThread(Socket accept) {
            this.accept = accept;
        }

        // run에 throw를 안하는 이유 --> 받을 객체가 없어서
        @Override
        public void run() {
            ObjectInputStream ois = null;
            ObjectOutputStream oos = null;
            try {
                // exceptino 발생 시 무한루프 빠져 나감
                while (true) {
                    ois = new ObjectInputStream(new BufferedInputStream(accept.getInputStream()));
                    ArrayList<Book> list = (ArrayList<Book>) ois.readObject();
                    print(list);

                    oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("Book.dat")));
                    oos.writeObject(list);
                    oos.flush();
                    oos.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            } finally {
                try {
                    oos.close();    // 출력 스트림 닫기
                    ois.close();    // 입력 스트림 닫기

                    for (int i = 0; i < clients.size(); i++) {
                        // 주소 비교
                        if (clients.get(i) == accept) {
                            System.out.println(clients.get(i).getInetAddress().getHostAddress() + " 님이 접속을 끊으셨습니다.");   // 클라이언트의 IP를 가져온다.
                            clients.remove(i);  // 종료한 클라이언트를 풀에서 삭제
                        }
                    }

                    // 소켓을 닫기 전에 client를 찾아 지워준다
                    accept.close(); // 소켓 닫기
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

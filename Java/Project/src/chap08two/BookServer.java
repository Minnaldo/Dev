package chap08two;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;


// connect를 하고 나서는, 서버와 클라이언트는 반대로 열어야 한다.
// Client : ouput on, input on 이면, Server : input on , ouput on 순서로 스트림을 열어야 한다.
public class BookServer {

    private ServerSocket ssock;

//    public void BookServer() throws IOException {
//        ssock = new ServerSocket(8080);
//    }

    void print(List<Book> list) {
        for (Book b : list) {
            System.out.println(b.toString());
        }
    }

    void go() throws IOException, ClassNotFoundException {
        ssock = new ServerSocket(8080);
        while (true) {
            System.out.println("[Server]  Waiting");
            Socket client = ssock.accept();

            ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(client.getInputStream()));
            print((ArrayList<Book>) ois.readObject());
        }

    }

    public static void main(String[] args) {
        try {
            new BookServer().go();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println(e.toString());
        }
    }
}

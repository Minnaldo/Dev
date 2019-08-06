package ws_java_0805;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class BookServer {
    public static void main(String[] args) {
        ObjectInputStream ois = null;
        try {
            ServerSocket ss = new ServerSocket(8080);
            Socket client = ss.accept();

            ois = new ObjectInputStream(new BufferedInputStream(client.getInputStream()));

            ArrayList<Book> ret = (ArrayList<Book>) ois.readObject();

            // 도서 정보 출력
            for (Book b : ret) {
                System.out.println(b.toString());
            }
        } catch (ClassNotFoundException | IOException e) {
            e.printStackTrace();
        } finally {
            try {
                ois.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}

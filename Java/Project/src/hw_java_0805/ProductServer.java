package hw_java_0805;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class ProductServer {
    public static void main(String[] args) {
        ObjectInputStream ois = null;
        ServerSocket ss = null;
        try {
            ss = new ServerSocket(8080);
            while (true) {
                Socket client = ss.accept();
                System.out.println("Client Connected");

                ois = new ObjectInputStream(new BufferedInputStream(client.getInputStream()));
                for (Product p : (ArrayList<Product>) ois.readObject()) {
                    System.out.println(p.toString());
                }

                if (client.isClosed()) {
                    break;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                ois.close();
                ss.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}

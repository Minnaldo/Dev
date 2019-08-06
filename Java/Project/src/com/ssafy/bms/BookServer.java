package com.ssafy.bms;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class BookServer {

    private static ServerSocket ssocket;
    private static Socket client;
    private static ObjectOutputStream oos;
    private static ObjectInputStream ois;
    private static ArrayList<Book> list;

    private static void go() throws IOException, ClassNotFoundException {
        ssocket = new ServerSocket(9090);
        client = ssocket.accept();
        // 클라이언트의 입력을 받는 스트림
        ois = new ObjectInputStream(new BufferedInputStream(client.getInputStream()));
        list = (ArrayList<Book>) ois.readObject();
        System.out.println("클라이언트로부터 받은 데이터");
        print(list);

        // 파일 저장 스트림
        oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("Book.dat")));
        oos.writeObject(list);
        oos.flush();
        System.out.println("파일 저장 완료");

        ois.close();
        oos.close();
    }

    private static void print(ArrayList<Book> arr) {
        for (Book b : arr) {
            System.out.println(b.toString());
        }
    }

    public static void main(String[] args) {
        try {
            new BookServer().go();
        } catch (IOException e) {
            e.getMessage();
        } catch (ClassNotFoundException e) {
            e.getMessage();
        }
    }
}

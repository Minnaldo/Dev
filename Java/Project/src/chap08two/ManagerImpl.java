package chap08two;

import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class ManagerImpl implements IManager {
    private ArrayList<Book> list;
    private static ManagerImpl instance = new ManagerImpl();

    public static ManagerImpl getInstance() {
        return instance;
    }

    private ManagerImpl() {
        list = new ArrayList<>();
    }

    @Override
    public void add(Book b) throws MyException {
        for (Book bb : list) {
            if (bb.getIsbn().equals(b.getIsbn())) {
                throw new MyException();
            }
        }

        list.add(b);
    }

    @Override
    public void update(Book b) throws MyException {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getIsbn().equals(b.getIsbn())) {
                list.set(i, b);
            }
        }
    }

    @Override
    public void delete(String isbn) throws MyException {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getIsbn().equals(isbn)) {
                list.remove(i);
            }
        }
    }

    @Override
    public List<Book> search() {
        return list;
    }

    @Override
    public Book search(String isbn) throws MyException {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getIsbn().equals(isbn)) {
                return list.get(i);
            }
        }
        throw new MyException();
    }

    @Override
    public void send() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    ObjectOutputStream oos = null;
                    Socket socket = new Socket("192.168.24.125", 7000);
                    oos = new ObjectOutputStream(new BufferedOutputStream(socket.getOutputStream()));
                    oos.writeObject(list);
                    oos.flush();
//                    oos.close();
                    System.out.println("서버로 전송 성공");
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }).start();
    }
}

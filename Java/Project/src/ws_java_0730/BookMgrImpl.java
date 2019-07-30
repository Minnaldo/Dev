package ws_java_0730;

import java.io.*;
import java.util.ArrayList;

public class BookMgrImpl implements IBookMgr {
    private static ArrayList<Book> barr = new ArrayList<>();
    private static BookMgrImpl instacne = new BookMgrImpl();

    public static BookMgrImpl getInstacne() {
        return instacne;
    }

    private BookMgrImpl() {
        open();
    }

    @Override
    public void add(Book b) {
        barr.add(b);
    }

    @Override
    public ArrayList<Book> search() {
        return barr;
    }

    @Override
    public void sell(String isbn, int quantity) throws QuantityException, ISBNNotFoundException {
        boolean flag = false;
        for (Book b : barr) {
            if (b.getIsbn().equals(isbn)) {
                flag = true;
                if (b.getQuantity() - quantity < 0) {
                    throw new QuantityException();
                } else {
                    b.setQuantity(b.getQuantity() - quantity);
                }
            }
        }
        if (!flag)
            throw new ISBNNotFoundException();
    }

    @Override
    public void buy(String isbn, int quantity) throws ISBNNotFoundException {
        boolean flag = false;
        for (Book b : barr) {
            if (b.getIsbn().equals(isbn)) {
                flag = true;
                b.setQuantity(b.getQuantity() + quantity);
            }
        }
        if (!flag)
            throw new ISBNNotFoundException();
    }

    @Override
    public int getTotalAmount() {
        int sum = 0;
        for (Book b : barr) {
            sum += (b.getPrice() * b.getQuantity());
        }
        return sum;
    }

    private static void open() {
        // file open
        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(new FileInputStream("book.dat"));
            // 객체 저장을 위한 다운캐스팅
            Book o;
            while ((o = (Book) ois.readObject()) != null) {
                barr.add(o);
            }
        } catch (FileNotFoundException e) {
//            e.printStackTrace();
            System.out.println("파일을 찾을 수 없습니다.");
        } catch (IOException e) {
//            e.printStackTrace();
        } catch (ClassNotFoundException e) {
//            e.printStackTrace();
        } finally {
            try {
                ois.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }

    public void close() {
        // file close and data save
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(new FileOutputStream("book.dat"));
            for (Book b : barr) {
                oos.writeObject(b);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            System.out.println("데이터 저장이 완료되었습니다.");
            try {
                oos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

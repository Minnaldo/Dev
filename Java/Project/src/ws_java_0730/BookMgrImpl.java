package ws_java_0730;

import java.io.*;
import java.util.ArrayList;

public class BookMgrImpl implements IBookMgr {
    private ArrayList<Book> barr;
    private static BookMgrImpl instacne = new BookMgrImpl();

    public static BookMgrImpl getInstacne() {
        return instacne;
    }

    private BookMgrImpl() {
        barr = open();
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
        for (Book b : barr) {
            if (b.getIsbn().equals(isbn)) {
                if (b.getQuantity() - quantity < 0) {
                    throw new QuantityException();
                } else {
                    b.setQuantity(b.getQuantity() - quantity);
                }
            }
        }
        throw new ISBNNotFoundException();
    }

    @Override
    public void buy(String isbn, int quantity) throws ISBNNotFoundException {
        for (Book b : barr) {
            if (b.getIsbn().equals(isbn)) {
                b.setQuantity(b.getQuantity() + quantity);
            }
        }
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

    private ArrayList<Book> open() {
        // file open
        ArrayList<Book> tmp = new ArrayList<>();
        try {
            ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("book.dat")));
            // 객체 저장을 위한 다운캐스팅
            Book tmpB;
            while ((tmpB = (Book) ois.readObject()) != null) {
                tmp.add(tmpB);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            return tmp;
        }
    }

    public void close() {
        // file close and data save
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("book.dat")));
            for (Book b : barr) {
                oos.writeObject(b);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            System.out.println("데이터 저장이 완료되었습니다.");
        }
    }
}

package hw_java_0729;

import java.util.ArrayList;

public class IBookMgrImpl implements IBookMgr {

    private ArrayList<Book> barr = new ArrayList<>();

    // apply singleton pattern
    private static IBookMgrImpl instance = new IBookMgrImpl();

    public static IBookMgrImpl getInstance() {
        return instance;
    }

    private IBookMgrImpl() {
    }

    @Override
    public void add(Book b) {
        barr.add(b);
    }

    @Override
    public ArrayList<Book> searchAll() {
        return barr;
    }

    @Override
    public ArrayList<Book> searchIsbn(String isbn) {
        ArrayList<Book> tmp = new ArrayList<>();
        for (Book b : barr) {
            if (b.getIsbn().equals(isbn)) {
                tmp.add(b);
            }
        }
        return tmp;
    }

    @Override
    public ArrayList<Book> searchTitle(String title) {
        ArrayList<Book> tmp = new ArrayList<>();
        for (Book b : barr) {
            if (b.getTitle().contains(title)) {
                tmp.add(b);
            }
        }
        return tmp;
    }

    @Override
    public ArrayList<Book> searchBook() {
        ArrayList<Book> tmp = new ArrayList<>();
        for (Book b : barr) {
            if (!(b instanceof Magazine)) {
                tmp.add(b);
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Book> searchMagzine() {
        ArrayList<Book> tmp = new ArrayList<>();
        for (Book b : barr) {
            if (b instanceof Magazine) {
                tmp.add(b);
            }
        }

        return tmp;
    }

    @Override
    public ArrayList<Book> searchMagzineInthisYear(int year) {
        ArrayList<Book> tmp = new ArrayList<>();
        for (Book b : barr) {
            if (b instanceof Magazine) {
                Magazine mg = (Magazine) b;
                if (mg.getYear() == year) {
                    tmp.add(b);
                }
            }
        }
        return tmp;
    }

    @Override
    public ArrayList<Book> searchPublisher(String publisher) {
        ArrayList<Book> tmp = new ArrayList<>();
        for (Book b : barr) {
            if (b.getPublisher().equals(publisher)) {
                tmp.add(b);
            }
        }
        return tmp;
    }

    @Override
    public ArrayList<Book> searchPrice(int price) {
        ArrayList<Book> tmp = new ArrayList<>();
        for (Book b : barr) {
            if (b.getPrice() < price) {
                tmp.add(b);
            }
        }
        return tmp;
    }


    @Override
    public int priceSum() {
        int sum = 0;
        for (Book b : barr) {
            sum += b.getPrice();
        }
        return sum;
    }

    @Override
    public int priceAvg() {
        int sum = 0;
        for (Book b : barr) {
            sum += b.getPrice();
        }
        return sum / barr.size();
    }
}

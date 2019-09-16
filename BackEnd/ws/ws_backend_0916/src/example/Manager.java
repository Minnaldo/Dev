package example;

import model.Book;

import java.util.ArrayList;

public class Manager {
    private ArrayList<Book> list = new ArrayList<>();

    private static Manager instance = new Manager();

    public static Manager getInstance() {
        return instance;
    }

    private Manager() {
    }

    public Book find(String isbn, String title) {
        Book ret = null;
        for (Book b : list) {
            if (b.getIsbn().equals(isbn) && b.getTitle().equals(title)) {
                ret = b;
                break;
            }
        }

        return ret;
    }

    public void add(String isbn, String title, String catalogue, String nation, String publishDate, String publisher, String author, String price, String desc) {
        list.add(new Book(isbn, title, catalogue, nation, publishDate, publisher, author, price, desc));
    }
}

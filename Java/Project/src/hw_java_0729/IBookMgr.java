package hw_java_0729;

import java.util.ArrayList;

public interface IBookMgr {
    void add(Book a);
    ArrayList<Book> searchAll();
    ArrayList<Book> searchIsbn(String isbn);
    ArrayList<Book> searchTitle(String title);
    ArrayList<Book> searchBook();
    ArrayList<Book> searchMagzine();
    ArrayList<Book> searchMagzineInthisYear(int year);
    ArrayList<Book> searchPublisher(String publisher);
    ArrayList<Book> searchPrice(int price);  // 이하 가격 검색
    int priceSum();
    int priceAvg();
}

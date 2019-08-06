package chap08two;

import java.util.List;

public interface IManager {
    void add(Book b) throws MyException;

    void update(Book b) throws MyException;

    void delete(String isbn) throws MyException;

    List<Book> search();

    Book search(String isbn) throws MyException;

    void send() ;

}

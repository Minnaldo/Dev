package ws0819;

import java.sql.SQLException;
import java.util.List;
import java.util.Scanner;

public class Test {
    private Scanner sc;
    private BookDAO man;

    public Test() {
        sc = new Scanner(System.in);
        man = new BookDAO();
//        try {
//            man.insertBook(new Book("a1101", "JAVA 기본", "자앤 기술연구소", "자앤 출판사", 23000, "기본"));
//            man.insertBook(new Book("a1102", "JAVA 중급", "자앤 기술연구소", "자앤 출판사", 25000, "중급"));
//            man.insertBook(new Book("a1103", "JAVA 실전", "자앤 기술연구소", "자앤 출판사", 30000, "실전"));
//        } catch (SQLException e) {
//            e.printStackTrace();
//        }
    }

    public static void main(String[] args) {
        new Test().go();
    }

    void printAllBooks(List<Book> list) {
        for (Book book : list) {
            System.out.println(book.toString());
        }
    }

    private void go() {
        while (true) {
            menu();
            int func = sc.nextInt();
            switch (func) {
                case 1:
                    insert();
                    break;
                case 2:
                    update();
                    break;
                case 3:
                    delete();
                    break;
                case 4:
                    search();
                    break;
                case 5:
                    list();
                    break;
                case 6:
                    count();
                    break;
                case 0:
                    close();
                    System.exit(0);
                    break;
            }
        }
    }

    private void close() {
    }

    private void count() {
        try {
            System.out.println(man.count() + "종류의 책이 있습니다.");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void list() {
        try {
            printAllBooks(man.listBooks());
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void search() {
        try {
            System.out.println("찾으려는 책의 isbn을 입력하세요");
            Book b = man.findBook(sc.next());
            if (b != null) {
                System.out.println(b.toString());
            } else {
                System.out.println("찾으시는 책이 존재하지 않습니다.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void delete() {
        System.out.println("삭제하려는 책의 isbn을 입력하세요");
        String isbn = sc.next();
        try {
            man.deleteBook(isbn);
            printAllBooks(man.listBooks());
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void update() {
        String isbn = sc.next();
        String title = sc.next();
        String author = sc.next();
        String publisher = sc.next();
        int price = sc.nextInt();
        String description = sc.next();
        try {
            man.updateBook(new Book(isbn, title, author, publisher, price, description));
            printAllBooks(man.listBooks());
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void insert() {
        String isbn = sc.next();
        String title = sc.next();
        String author = sc.next();
        String publisher = sc.next();
        int price = sc.nextInt();
        String description = sc.next();
        try {
            man.insertBook(new Book(isbn, title, author, publisher, price, description));
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void menu() {
        System.out.println("1. 삽입  " +
                "2. 수정  " +
                "3. 삭제  " +
                "4. 검색  " +
                "5. 조회  " +
                "6. 책 종류  " +
                "0. 종료");
    }
}

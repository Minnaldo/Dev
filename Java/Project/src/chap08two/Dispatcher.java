package chap08two;

import java.util.List;
import java.util.Scanner;

public class Dispatcher {

    // 인스턴스 형으로 가져옴
    private IManager man;
    private Scanner sc;
    private int menu;

    public Dispatcher() {
        man = ManagerImpl.getInstance();
        sc = new Scanner(System.in);
    }

    public void go() {
        while (true) {
            System.out.println("번호를 입력하세요\n" +
                    "1. 입력\n" +
                    "2. 조회\n" +
                    "3. 전송\n" +
                    "99. 종료");

            menu = sc.nextInt();

            switch (menu) {
                case 1:
                    System.out.println("isbn title 가격을 입력하세요");
                    String isbn = sc.next();
                    String title = sc.next();
                    int price = sc.nextInt();
                    try {
                        man.add(new Book(isbn, title, price));
                    } catch (MyException e) {
                        e.printStackTrace();
                    }
                    break;
                case 2:
                    print(man.search());
                    break;
                case 3:
                    man.send();
                    break;
                default:
                    // 정상 종료
                    System.exit(0);
                    break;
            }
        }
    }

    void print(List<Book> list) {
        for (Book b : list) {
            System.out.println(b.toString());
        }
    }

    public static void main(String[] args) {
        new Dispatcher().go();
    }
}

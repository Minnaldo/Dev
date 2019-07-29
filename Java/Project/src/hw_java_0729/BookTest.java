package hw_java_0729;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Scanner;

public class BookTest {
    private static void printFunc() {
        System.out.println("1. 데이터 입력 기능 ");
        System.out.println("2. 데이터 전체 검색 기능 ");
        System.out.println("3. Isbn으로 정보를 검색하는 기능");
        System.out.println("4. Title로 정보를 검색하는 기능(파라미터로 주어진 제목을 포함하는 모든 정보");
        System.out.println("5. Book만 검색하는 기능");
        System.out.println("6. Magazine만 검색하는 기능");
        System.out.println("7. 출판사로 검색하는 기능 ");
        System.out.println("8. 가격으로 검색 기능 (파라미터로 주어진 가격보다 낮은 도서 정보 검색)");
        System.out.println("9. 저장된 모든 도서의 금액 합계를 구하는 기능");
        System.out.println("10. 저장된 모든 도서의 금액 평균를 구하는 기능");
        System.out.println("0. 그만하려면 0을 눌러요 !");
    }

    public static void main(String[] args) {
        IBookMgrImpl bm = IBookMgrImpl.getInstance();
        Scanner sc = new Scanner(System.in);
        ArrayList<Book> tmp = new ArrayList<>();
        printFunc();
        boolean exitFlag = false;
        while (!exitFlag) {
            switch (sc.nextInt()) {
                case 0:
                    exitFlag = true;
                    System.out.println("프로그램을 종료합니다");
                    break;
                case 1:
                    System.out.println("1. 책 입력, 2. 잡지 입력, 0. 종료");
                    switch (sc.nextInt()) {
                        case 1:
                            System.out.println("1. book 데이터 입력 (isbn, title, author, publisher, price(int), desc(int)");
                            String[] str = sc.next().toUpperCase().replaceAll(" ", "").trim().split(",");
                            bm.add(new Book(str[0], str[1], str[2], str[3], Integer.parseInt(str[4]), str[5]));
                            break;
                        case 2:
                            System.out.println(
                                    "2. Magazine 데이터 입력(isbn, title, author, publisher, price(int), desc(int), year, month");
                            String[] str1 = sc.next().toUpperCase().replaceAll(" ", "").trim().split(",");
                            bm.add(new Magazine(str1[0], str1[1], str1[2], str1[3], Integer.parseInt(str1[4]), str1[5],
                                    Integer.parseInt(str1[6]), Integer.parseInt(str1[7])));
                            break;
                        case 0:
                            break;
                    }
                case 2:
                    System.out.println("저장된 자료를 모두 검색합니다");
                    tmp = bm.searchAll();
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 3:
                    System.out.println("isbn을 입력해 주세요");
                    tmp = bm.searchIsbn(sc.next().toUpperCase().trim());
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 4:
                    System.out.println("책 제목을 입력해 주세요");
                    tmp = bm.searchTitle(sc.next().toUpperCase().trim());
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 5:
                    System.out.println("책만 검색합니다");
                    tmp = bm.searchBook();
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 6:
                    tmp = bm.searchMagzine();
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 7:
                    System.out.println("올해 발간된 잡지만 검색합니다");
                    tmp = bm.searchMagzineInthisYear(Calendar.getInstance().get(Calendar.getInstance().YEAR));  // 날짜를 가져온다
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 8:
                    System.out.println("검색하려는 출판사를 입력해주세요");
                    tmp = bm.searchPublisher(sc.next().toUpperCase().trim());
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 9:
                    System.out.println("입력하신 가격 미만의 도서를 검색합니다");
                    tmp = bm.searchPrice(sc.nextInt());
                    for (Book b : tmp)
                        b.toString();
                    tmp.clear();
                    break;
                case 10:
                    System.out.println(bm.priceSum());
                    break;
                case 11:
                    System.out.println(bm.priceAvg());
                    break;
            }
        }
    }
}
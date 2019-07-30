package ws_java_0730;

import java.util.ArrayList;
import java.util.Scanner;

public class BookTest {

    private static void printFunc() {
        System.out.println("<<<    사용할 기능을 선택해 주세요    >>>\n" +
                "1. 도서 입력\n" +
                "2. 전체 도서 검색\n" +
                "3. 도서 판매\n" +
                "4. 도서 구매\n" +
                "5. 총 재고 금액");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BookMgrImpl bm = BookMgrImpl.getInstacne();

        bm.add(new Book("ISBN", "title1", 10000, 10));
        bm.add(new Book("ISBN1", "title2", 12000, 5));
        bm.add(new Book("ISBN2", "title3", 15000, 13));
        bm.add(new Magazine("ISBN01", "Magazine1", 13000, 1, 1));
        bm.add(new Magazine("ISBN00", "Magazine2", 9000, 10, 2));
        bm.add(new Magazine("ISBN03", "Magazine3", 15000, 11, 7));
        bm.add(new Magazine("ISBN06", "Magazine6", 8000, 7, 12));


        boolean exitFlag = false;

        while (!exitFlag) {
            printFunc();
            switch (sc.nextInt()) {
                case 1: //add
                    System.out.println("1. 책, 2. 잡지, 0. 돌아가기");
                    switch (sc.nextInt()) {
                        case 1:
                            System.out.println("\"isbn,title,price,quantity\" 형식으로 입력해주세요");
                            String[] str = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                            bm.add(new Book(str[0], str[1], Integer.parseInt(str[2]), Integer.parseInt(str[3])));
                            break;
                        case 2:
                            System.out.println("\"isbn,title,price,quantity,month\" 형식으로 입력해주세요");
                            String[] str1 = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                            bm.add(new Magazine(str1[0], str1[1], Integer.parseInt(str1[2]), Integer.parseInt(str1[3]), Integer.parseInt(str1[4])));
                            break;
                        case 0:
                            break;
                        default:
                            System.out.println("잘못 입력하셨습니다. 올바른 값을 입력해 주세요");
                    }
                    break;
                case 2: // search
                    ArrayList<Book> tmpArr = bm.search();
                    for (Book b : tmpArr)
                        System.out.println(b.toString());
                    System.out.println("검색이 끝났습니다.");
                    break;
                case 3: // sell
                    System.out.println("책의 isbn과 판매 수량을 입력해주세요");
                    try {
                        bm.sell(sc.next().toUpperCase(), sc.nextInt());
                    } catch (QuantityException e) {
                        e.printStackTrace();
                    } catch (ISBNNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case 4: // buy
                    System.out.println("책의 isbn과 구매 수량을 입력해주세요");
                    try {
                        bm.buy(sc.next().toUpperCase(), sc.nextInt());
                    } catch (ISBNNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case 5: // getTotalAmount
                    System.out.println("재고의 총 합은 : " + bm.getTotalAmount() + "원 입니다.");
                    break;
                case 0:
                    System.out.println("프로그램을 종료합니다.");
                    exitFlag = true;
                    bm.close();
                    break;
                default:
                    System.out.printf("잘못 입력하셨습니다. 다시 입력해주세요");
            }
        }
    }
}

package hw_java_0805;

import java.util.Scanner;

public class ProductTest {
    private static void printFunc() {
        System.out.println("<<<    사용할 기능을 선택해 주세요    >>>\n" +
                "1. 상품 추가\n" +
                "2. 전체 상품 검색\n" +
                "3. 상품번호로 검색\n" +
                "4. 상품명으로 검색(부분검색 지원)\n" +
                "5. TV만 검색\n" +
                "6. 냉장고만 검색\n" +
                "7. 400L 이상의 냉장고만 검색\n" +
                "8. 50inch 이상의 TV만 검색\n" +
                "9. 상품 가격 변겅\n" +
                "10. 상품 삭제\n" +
                "11. 재고 상품 금액 합계\n" +
                "12. 상품 목록 저장\n" +
                "13. 상품 목록 서버로 전송\n" +
                "0. 프로그램 종료");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ProductMgrImpl pm = ProductMgrImpl.getInstance();
        boolean exitFlag = false;


        try {
            pm.add(new Refrigerator(200, "REF1", 10000, 10, 30));
            pm.add(new Refrigerator(201, "REF2", 15000, 10, 45));
            pm.add(new Refrigerator(202, "REF3", 55000, 10, 200));
            pm.add(new Refrigerator(205, "REF5", 10000, 15, 330));
//            pm.add(new TV(100, "TV1", 10000, 10, 10));  // 여기서 에러가 발생할 것
            pm.add(new TV(100, "TV1", 10000, 10, 11));
            pm.add(new TV(101, "TV2", 5000, 40, 45));
            pm.add(new TV(102, "TV3", 50000, 50, 30));
        } catch (DuplicateException e) {
//            e.printStackTrace();
            System.err.println("이미 존재하는 상품입니다. 다시 확인하고 입력해 주세요");
        }


        while (!exitFlag) {
            printFunc();
            switch (sc.nextInt()) {
                case 1:
                    System.out.println("1. TV 추가, 2. 냉장고 추가, 0. 돌아가기");
                    switch (sc.nextInt()) {
                        case 1:
                            try {
                                System.out.println("\"제품번호, 제품명, 가격 정보, 재고수량, 화면크기\" 형식으로 입력해주세요");
                                String[] tmp = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                                pm.add(new TV(Integer.parseInt(tmp[0]), tmp[1], Integer.parseInt(tmp[2]), Integer.parseInt(tmp[3]), Integer.parseInt(tmp[4])));
                            } catch (DuplicateException e) {
                                e.printStackTrace();
                            }
                            break;
                        case 2:
                            try {
                                System.out.println("\"제품번호, 제품명, 가격 정보, 재고수량, 용량\" 형식으로 입력해주세요");
                                String[] tmp1 = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                                pm.add(new Refrigerator(Integer.parseInt(tmp1[0]), tmp1[1], Integer.parseInt(tmp1[2]), Integer.parseInt(tmp1[3]), Integer.parseInt(tmp1[4])));
                            } catch (DuplicateException e) {
                                e.printStackTrace();
                            }
                            break;
                        case 0:
                            break;
                        default:
                            System.out.println("잘못된 값을 입력했습니다. 올바른 값을 입력해 주세요");
                    }
                    break;
                case 2:
                    System.out.println("전체 상품을 검색합니다");
                    for (Product p : pm.searchAll())
                        System.out.println(p.toString());
                    break;
                case 3:
                    System.out.println("상품번호로 검색합니다. 검색하려는 상품의 번호를 입력해주세요");
                    try {
                        for (Product p : pm.searchProNum(sc.nextInt()))
                            System.out.println(p.toString());
                    } catch (CodeNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case 4:
                    System.out.println("상품명으로 검색합니다. 검색하려는 상품의 상품명을 입력해주세요");
                    for (Product p : pm.searchName(sc.next().toUpperCase()))
                        System.out.println(p.toString());
                    break;
                case 5:
                    System.out.println("TV 정보만 검색합니다.");
                    for (Product p : pm.searchOnlyTv())
                        System.out.println(p.toString());
                    break;
                case 6:
                    System.out.println("냉장고 정보만 검색합니다");
                    for (Product p : pm.searchOnlyRefrigerator())
                        System.out.println(p.toString());
                    break;
                case 7:
                    try {
                        System.out.println("400L 이상의 냉장고만 검색합니다");
                        for (Product p : pm.searchUpTo400Liter())
                            System.out.println(p.toString());
                    } catch (ProductNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case 8:
                    try {
                        System.out.println("50inch 이상의 TV만 검색합니다");
                        for (Product p : pm.searchUpTo50inch())
                            System.out.println(p.toString());
                    } catch (ProductNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case 9:
                    System.out.println("상품의 가격을 변경합니다. 상품번호와 바꿀 가격을 입력해주세요");
                    pm.changeProductPrice(sc.nextInt(), sc.nextInt());
                    break;
                case 10:
                    System.out.println("상품을 삭제합니다. 삭제하려는 상품의 상품번호를 입력해주세요");
                    pm.removeProduct(sc.nextInt());
                    break;
                case 11:
                    System.out.println("전체 재고 상품 금액의 합은 " + pm.priceSum() + "원 입니다.");
                    break;
                case 12:
                    // 파일로 저장
                    pm.close();
                    break;
                case 13:
                    // 서버로 전송
                    pm.send();
                    break;
                case 0:
                    System.out.println("프로그램을 종료합니다");
                    exitFlag = true;
                    break;
                default:
                    System.out.println("잘못 입력하셨습니다. 올바른 값을 입력해 주세요");
            }
        }

    }
}

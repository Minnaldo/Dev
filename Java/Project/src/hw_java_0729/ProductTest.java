package hw_java_0729;

import java.util.Scanner;

public class ProductTest {

    private static void printFunc() {
        System.out.println("1. 상품 추가\n" +
                "2. 전체 상품 검색\n" +
                "3. 상품번호로 검색\n" +
                "4. 상품명으로 검색(부분검색 지원)\n" +
                "5. TV만 검색\n" +
                "6. 냉장고만 검색\n" +
                "7. 400L 이상의 냉장고만 검색\n" +
                "8. 50inch 이상의 TV만 검색\n" +
                "9. 상품 가격 변겅\n" +
                "10. 상품 삭제\n" +
                "11. 재고 상품 금액 합계");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ProductMgrImpl pm = ProductMgrImpl.getInstance();
        boolean exitFlag = false;
        while (!exitFlag) {
            printFunc();
            switch (sc.nextInt()) {
                case 1:
                    System.out.println("1. TV 추가, 2. 냉장고 추가, 0. 돌아가기");
                    switch (sc.nextInt()) {
                        case 1:
                            System.out.println("\"제품번호,제품명,가격 정보, 재고수량, 화면크기\" 형식으로 입력해주세요");
                            String[] tmp = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                            pm.add(new TV(Integer.parseInt(tmp[0]), tmp[1], Integer.parseInt(tmp[2]), Integer.parseInt(tmp[3]), Integer.parseInt(tmp[4])));
                            break;
                        case 2:
                            System.out.println("\"제품번호,제품명,가격 정보, 재고수량, 용량\" 형식으로 입력해주세요");
                            String[] tmp1 = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                            pm.add(new Refrigerator(Integer.parseInt(tmp1[0]), tmp1[1], Integer.parseInt(tmp1[2]), Integer.parseInt(tmp1[3]), Integer.parseInt(tmp1[4])));
                            break;
                        case 0:
                            break;
                        default:
                    }
                    break;
                case 2:
                    System.out.println("전체 상품을 검색합니다");
                    for (Product p : pm.searchAll())
                        System.out.println(p.toString());
                    break;
                case 3:
                    System.out.println("상품번호로 검색합니다. 검색하려는 상품의 번호를 입력해주세요");
                    for (Product p : pm.searchProNum(sc.nextInt()))
                        System.out.println(p.toString());
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
                    System.out.println("400L 이상의 냉장고만 검색합니다");
                    for (Product p : pm.searchUpTo400Liter())
                        System.out.println(p.toString());
                    break;
                case 8:
                    System.out.println("50inch 이상의 TV만 검색합니다");
                    for (Product p : pm.searchUpTo50inch())
                        System.out.println(p.toString());
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
                case 0:
                    System.out.println("프로그램을 종료합니다");
                    break;
                default:
            }
        }

    }
}

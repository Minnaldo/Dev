import java.util.Scanner;

public class ProductTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ProductMgr pm = new ProductMgr();

        boolean flag = false;
        while (!flag) {
            System.out.println("이용하실 기능을 선택해주세요");
            System.out.println("1 : 상품 추가  2 : 전체 검색  3 : 상품번호로 검색  4 : 상품명으로 검색  5 : TV만 검색\n6 : Refrigerator만 검색  7 : 상품 번호로 삭제  8 : 전체 상품 재고 합계  0 :  프로그램종료");
            switch (sc.nextInt()) {
                case 1:
                    try {
                        System.out.println("1 : TV,  2 : Refrigerator,  0 : 돌아가기");
                        int fnum = sc.nextInt();
                        if (fnum == 1) {  // TV 추가
                            System.out.println("\"제품번호,제품명,가격정보,재고수량,디스플레이크기,디스플레이타입\"형태로 입력해주세요");
                            String[] dataStr = sc.next().split(",");
                            pm.addProduct(new TV(Integer.parseInt(dataStr[0]), dataStr[1].toUpperCase(), Integer.parseInt(dataStr[2]), Integer.parseInt(dataStr[3]), Integer.parseInt(dataStr[4]), dataStr[5].toUpperCase()));
                            System.out.println("TV를 추가하였습니다");
                        } else if (fnum == 2) {  // Refrigerator 추가
                            System.out.println("\"제품번호,제품명,가격정보,재고수량,용량\"형태로 입력해주세요");
                            String[] dataStr = sc.next().replaceAll(" ", "").split(",");  // 공백 제거후 스플릿
                            pm.addProduct(new Refrigerator(Integer.parseInt(dataStr[0]), dataStr[1].toUpperCase(), Integer.parseInt(dataStr[2]), Integer.parseInt(dataStr[3]), Integer.parseInt(dataStr[4])));
                            System.out.println("Refrigerator를 추가하였습니다");
                        } else if (fnum == 0) {
                            System.out.print("상품 추가를 종료합니다");
                        }
                    } catch (Exception e) {
//                        System.out.println("잘못된 값을 입력하셨습니다. 올바른 값을 입력해주세요");
                        e.printStackTrace();
                    }
                    break;
                case 2:
                    System.out.println("모든 상품을 검색 합니다.");
                    System.out.println(pm.searchAll());
                    break;
                case 3:
                    System.out.println("상품 번호로 상품을 검색합니다. 상품 번호를 입력해 주세요");
                    System.out.println(pm.searchProductNum(sc.nextInt()));
                    break;
                case 4:
                    System.out.println("상품명으로 상품을 검색합니다");
                    System.out.println(pm.searchName(sc.next().toUpperCase().trim()));
                    break;
                case 5:
                    System.out.println("TV 정보만 검색합니다.");
                    System.out.println(pm.searchTV());
                    break;
                case 6:
                    System.out.println("Refrigerator 정보만 검색합니다.");
                    System.out.println(pm.searchRefrigerator());
                    break;
                case 7:
                    System.out.println("번호로 상품을 삭제합니다. 삭제하시려는 상품 번호를 입력해 주세요");
                    pm.delNum(sc.nextInt());
                    break;
                case 8:
                    System.out.println("모든 재고상품의 상품 금액 합계는 : " + pm.getStockPriceSum() + "원 입니다.");
                    break;
                case 9:
                    System.out.println("찾고자 하는 용량을 입력해 주세요.");
                    pm.searchVol(sc.nextInt());
                    break;
                case 10:
                    System.out.println("찾고자 하는 화면 크기를 입력해 주세요.");
                    pm.searchInch(sc.nextInt());
                    break;
                case 0:
                    System.out.println("프로그램을 종료합니다.");
                    flag = true;
                    break;
                default:
                    System.out.println("잘못 입력하셨습니다. 다시 입력해 주세요");
                    break;
            }
        }
    }

}

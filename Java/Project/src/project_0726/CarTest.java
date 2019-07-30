package project_0726;

import java.util.Scanner;

public class CarTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        /** CarMgr클래스의 싱글톤 패턴을 이용한 기능 제공*/
        // 싱글톤 패턴은 클래스 생성시 한번만 메모리에 올라가고, 이후에 올라가지 않는다.
        CarMgr cm = CarMgr.getInstance();
        boolean exitFlag = false;

        while (!exitFlag) {
            System.out.println("이용하실 기능을 선택해주세요");
            System.out.println("1. 차량 추가, 2. 모두 검색, 3. 번호로 검색, 4. 가격으로 검색, 5. 차량 정보 업데이트, 6. 차량 정보 제거, 7. 저장된 차량의 수 출력, 8. 저장된 차량의 가격 합계, 0. 프로그램 종료");
            switch (sc.nextInt()) {
                case 1: // add
                    System.out.println("추가할 차량의 종류를 선택해 주세요");
                    System.out.println("1. 버스, 2. 트럭, 3. 종료");
                    switch (sc.nextInt()) {
                        case 1:
                            System.out.println("\"차량 번호, 모델, 가격, 좌석 수\" 형식으로 입력해 주세요");
                            String[] tmpStr1 = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                            cm.add(new Bus(tmpStr1[0], tmpStr1[1], Integer.parseInt(tmpStr1[2]), Integer.parseInt(tmpStr1[3])));
                            break;
                        case 2:
                            System.out.println("차량 번호, 모델, 가격, 톤 형식으로 입력해 주세요");
                            String[] tmpStr = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                            cm.add(new Truck(tmpStr[0], tmpStr[1], Integer.parseInt(tmpStr[2]), Integer.parseInt(tmpStr[3])));
                            break;
                        case 0:
                            System.out.println("차량 추가를 종료합니다");
                            break;
                        default:
                            System.out.println("잘못 입력하셨습니다. 첫화면으로 돌아갑니다.");
                    }
                    break;
                case 2: // search All
                    System.out.println("저장된 모든 차량을 검색합니다.");
                    Car[] tmp = cm.search();
                    if (tmp != null)
                        for (int i = 0; i < tmp.length; i++) {
                            if (tmp[i] != null) {
                                System.out.println(tmp[i].toString());
                            }
                        }
                    break;
                case 3: //search for num
                    System.out.println("검색할 차량의 번호를 입력해 주세요");
                    System.out.println(cm.search(sc.next()).toString());
                    break;
                case 4: // search for price
                    System.out.println("검색할 가격을 적어주세요");
                    Car[] tmp1 = cm.search(sc.nextInt());
                    for (int i = 0; i < tmp1.length; i++) {
                        if (tmp1[i].getNum() != null)
                            System.out.println(tmp1[i].toString());
                    }
                    break;
                case 5: // update car's data
                    System.out.println("\"차량번호,업데이트 가격\" 형식으로 입력해 주세요");
                    String[] up = sc.next().replaceAll(" ", "").split(",");
                    cm.update(up[0], Integer.parseInt(up[1]));
                    break;
                case 6: //  delete car's data
                    System.out.println("지울 차 번호를 입력해 주세요");
                    cm.delete(sc.next());
                    break;
                case 7: // return car size
                    System.out.println(cm.size() + "대의 차가 저장되어 있습니다.");
                    break;
                case 8: // return total sum
                    System.out.println("저장된 차량의 가격 합계는 " + cm.totalPrice() + "원 입니다.");
                    break;
                case 0:
                    System.out.println("프로그램을 종료합니다.");
                    exitFlag = true;
                    break;
                default:
                    System.out.println("잘못 입력하셨습니다. 올바른 값을 입력해 주세요");
            }
        }
    }
}

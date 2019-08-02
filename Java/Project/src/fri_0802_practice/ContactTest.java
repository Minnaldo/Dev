package fri_0802_practice;

import java.util.Scanner;

public class ContactTest {

    private static void printFunc() {
        System.out.println("<<<< 기능을 선택해 주세요 >>>>");
        System.out.println("1. 연락처 추가\n" +
                "2. 연락처 삭제\n" +
                "3. 연락처 수정\n" +
                "4. 연락처 검색\n" +
                "5. 모든 연락처\n" +
                "0. 종료");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ContactMgr cm = ContactMgr.getInstance();
        boolean exitFlag = false;
        while (!exitFlag) {
            printFunc();
            switch (sc.nextInt()) {
                case 1: {
                    System.out.print("번호 : ");
                    String num = sc.next();
                    System.out.print("이름 : ");
                    String name = sc.next();
                    System.out.print("회사 : ");
                    String company = sc.next();
                    try {
                        cm.add(new Contact(num, name, company));
                    } catch (DuplicateContactException e) {
//                        e.printStackTrace();
                        System.out.println("이미 존재하는 이름입니다.");
                    }
                }
                break;
                case 2:
                    System.out.println("삭제할 이름은?");
                    try {
                        cm.delete(sc.next());
                    } catch (ContactNotFoundException e) {
//                        e.printStackTrace();
                        System.out.println("존재 하지 않는 연락처 입니다.");
                    }
                    break;
                case 3:
//                    cm.update(name, num);
                    break;
                case 4:
                    System.out.println("찾을 연락처의 이름은?");

                    break;
                case 5:
                    for (Contact c : cm.search(sc.next())) {
                        System.out.println(c.toString());
                    }
                    break;
                case 0:
                    exitFlag = true;
                    System.out.println("종료합니다");
                    break;
                default:
                    System.out.println("다시 ");
                    break;
            }
        }
    }
}

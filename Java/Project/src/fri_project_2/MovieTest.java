package fri_project_2;

import java.util.Scanner;

public class MovieTest {

    public static void printFunct() {
        System.out.println("1. 영화 정보 입력");
        System.out.println("2. 영화 정보 전체 검색");
        System.out.println("3. 영화명 검색");
        System.out.println("4. 영화 장르별 검색");
        System.out.println("5. 영화 감독별 검색");
        System.out.println("6. 영화 정보 삭제");
        System.out.println("0. 종료");
        System.out.println("원하는 번호를 선택하세요.");
    }

    public static void main(String[] args) {
        System.out.println("<<< 영화 관리 프로그램 >>>");
        Scanner sc = new Scanner(System.in);
        MovieMgr mm = MovieMgr.getInstance();

        boolean exitFlag = false;

        while (!exitFlag) {
            printFunct();
            switch (sc.nextInt()) {
                case 1:
                    System.out.println("\"제목, 감독, 등급, 장르\" 또는 \"제목, 감독, 등급, 장르, 줄거리\" 형식으로 입력해 주세요.");
                    String[] data = sc.next().toUpperCase().replaceAll(" ", "").split(",");
                    if (data.length == 4)
                        mm.add(new Movie(data[0], data[1], Integer.parseInt(data[2]), data[3]));
                    else if( data.length == 5)
                        mm.add(new Movie(data[0], data[1], Integer.parseInt(data[2]), data[3], data[4]));
                    break;
                case 2:
                    System.out.println("모든 영화 정보를 검색합니다.");
                    Movie[] tmp = mm.search();
                    for (int i = 0; i < tmp.length; i++) {
                        System.out.println(tmp[i].toString());
                    }
                    break;
                case 3:
                    System.out.println("영화 제목으로 검색합니다.");
                    Movie[] tmp1 = mm.search(sc.next().trim().toUpperCase());
                    for (int i = 0; i < tmp1.length; i++) {
                        System.out.println(tmp1[i].toString());
                    }
                    break;
                case 4:
                    System.out.println("영화 장르로 검색합니다.");
                    Movie[] tmp2 = mm.searchGenre(sc.next().trim().toUpperCase());
                    for (int i = 0; i < tmp2.length; i++) {
                        System.out.println(tmp2[i].toString());
                    }
                    break;
                case 5:
                    System.out.println("영화 감독으로 검색합니다");
                    Movie[] tmp3 = mm.searchDirector(sc.next().toUpperCase().trim());
                    for (int i = 0; i < tmp3.length; i++) {
                        System.out.println(tmp3[i].toString());
                    }
                    break;
                case 6:
                    System.out.println("영화 제목으로 정보를 삭제합니다.");
                    mm.delete(sc.next().toUpperCase().trim());
                    System.out.println("남아 있는 영화 데이터 : " + mm.size());
                    break;
                case 0:
                    exitFlag = true;
                    break;

            }
        }


    }
}

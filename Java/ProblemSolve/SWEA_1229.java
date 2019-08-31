import java.util.*;

import java.io.*;

public class SWEA_1229 {
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            for (int tc = 1; tc <= 10; tc++) {

                // 중간의 sc.nextLine()은 공백을 지우기 위해
                int n = sc.nextInt();
                sc.nextLine();
                String chiper = sc.nextLine().replaceAll(" ", "");
                int iLen = sc.nextInt();
                sc.nextLine();

                StringBuilder sb = new StringBuilder(chiper);

                // TODO 19.08.01
                // * 새로운 스캐너를 이용했더니 답이 제대로 나왔다..? 왜그럴까..??
                Scanner sc2 = new Scanner(sc.nextLine());
                int x, y;
                String tmpStr;
                // 명령어를 하나씩 입력받자
                while (sc2.hasNext()) {
                    char c = sc2.next().charAt(0);
                    switch (c) {
                    case 'I':
                        x = sc2.nextInt();
                        y = sc2.nextInt();
                        tmpStr = "";
                        for (int a = 0; a < y; a++) {
                            tmpStr += sc2.next();
                        }
                        sb.insert(x * 6, tmpStr);
                        break;
                    case 'D':
                        int delIdx = sc2.nextInt() * 6;
                        sb.delete(delIdx, delIdx + (sc2.nextInt() * 6));
                        break;
                    case 'A':
                        y = sc2.nextInt();
                        tmpStr = "";
                        for (int a = 0; a < y; a++) {
                            tmpStr += sc2.next();
                        }
                        sb.append(tmpStr);
                        break;
                    }
                }

                System.out.print("#" + tc + " ");
                for (int i = 0; i < 9; i++) {
                    System.out.print(sb.substring(i * 6, i * 6 + 6) + " ");
                }
                System.out.println(sb.substring(54, 60));
                sc2.close();
            }
            sc.close();
    }
}
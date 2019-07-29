import java.util.Scanner;
import java.io.*;

public class SWEA_1216 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);

            for (int tc = 1; tc <= 10; tc++) {
                int ans = 0;
                int tmpTc = sc.nextInt();
                String[] map = new String[100];

                for (int i = 0; i < 100; i++) {
                    map[i] = sc.next();
                }

                // 0~99, i/100-i
                // 가로방향 보면서
                // a는 map을 돈다
                for (int a = 0; a < 100; a++) {
                    // i와 j 위치의 문자열을 비교
                    int len = 2;
                    int start = 0;
                    int end = 99;

                    while (start++ <= end) {
                        boolean flag = false;
                        for (int i = start; i < 100; i++) {
                            for (int j = end; j >= i; j--) {
                                if (map[a].charAt(i) != map[a].charAt(j)) {
                                    flag = true;
                                    len = 2;
                                    // 안쪽 for문 나가기
                                    break;
                                }
                                len++;

                                if ((j - i == 2 && map[a].charAt(i) == map[a].charAt(j))
                                        || (i - j == 3 && map[a].charAt(i) == map[a].charAt(j))) {
                                    ans = ans > len ? ans : len;
                                }

                            }
                            if (flag) {
                                // 바깥 for문 나가기
                                break;
                            }
                        }
                        start++;
                    }
                }

                for (int a = 0; a < 100; a++) {
                    // i와 j 위치의 문자열을 비교
                    int len = 2;
                    int start = 0;
                    int end = 99;

                    while (start++ <= end) {
                        boolean flag = false;
                        for (int i = start; i < 100; i++) {
                            for (int j = end; j >= i; j--) {
                                if (map[i].charAt(a) != map[j].charAt(a)) {
                                    flag = true;
                                    len = 2;
                                    // 안쪽 for문 나가기
                                    break;
                                }
                                len++;
                                if ((j == j && map[i].charAt(a) == map[j].charAt(a))
                                        || (i - j == 1 && map[i].charAt(a) == map[j].charAt(a))) {
                                    ans = ans > len ? ans : len;
                                }

                            }
                            if (flag) {
                                // 바깥 for문 나가기
                                break;
                            }
                        }
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
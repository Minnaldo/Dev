import java.util.Scanner;
import java.io.*;

public class SWEA_1216 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("test.txt")) {
            Scanner sc = new Scanner(fis);

            for (int tc = 1; tc <= 1; tc++) {
                int ans = 0;
                int tmpTc = sc.nextInt();
                String[] map = new String[8];

                for (int i = 0; i < 8; i++) {
                    map[i] = sc.next();
                }

                for (String aa : map) {
                    System.out.println(aa);
                }

                // System.out.println("start!");
                // 100 개의 string을 돈다
                for (int a = 0; a < 8; a++) {
                    // 앞쪽 인덱스 고정
                    // 뒤에서부터 같은지 비교해온다
                    // 같으면 앞쪽 인덱스++, 뒤쪽인덱스--
                    // 위를 반복해오다 각 인덱스의 값이 다르면
                    // 회문일 조건 : 뒤 인덱스 == 앞 인덱스(짝수 자릿수 회문) || 뒤 인덱스 - 앞 인덱스 == 2 (홀수 자릿수 회문)
                    // 회문이 아니면 : 길이 체크 변수 0으로 초기화 / 앞쪽 인덱스를 기억하고 있는 변수 + 1 / 뒤쪽 인덱스 변수는 99로

                    String str = map[a];
                    // 앞쪽 && 뒤쪽 인덱스를 기억하고 있을 변수
                    int front = 0;
                    int back = 7;

                    int start = front;
                    int end = back;
                    int len = 0;
                    while (start <= end) {
                        // 회문일 조건
                        if (end - start == 2 || end == start) {
                            ans = ans > len ? ans : len;
                            break;
                        }

                        if (str.charAt(start) == str.charAt(end)) {
                            end--;
                            start++;
                            len += 2;
                        } else {
                            len = 0;
                            start = ++front;
                            end = back;
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
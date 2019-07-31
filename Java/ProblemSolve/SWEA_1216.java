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

                // for (String aa : map) {
                // System.out.println(aa);
                // }

                System.out.println("start!");
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

                    // int start = front;
                    // int end = back;
                    // int len = 0;

                    for (int j = 0; j < back; j++) {
                        // 현재 문자열의 길이
                        int size = (back - j + 1);
                        if (size % 2 == 0) {
                            size = size / 2 + 1;
                            // System.out.println("짝수");
                        } else {
                            size = size / 2;
                            // System.out.println("홀수");
                        }

                        boolean flag = false;

                        for (int i = j; i < size; i++) {
                            if (str.charAt(i) != str.charAt(str.length() - (i + 1))) {
                                flag = true;
                                break;
                            }
                        }

                        if (!flag) {
                            System.out.print("회문  + " + size);
                            ans = ans > size ? ans : size;
                            // System.out.printf(" ans :%3d size :%3d", ans, size);
                        }
                    }
                    System.out.println();
                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (

        Exception e) {
            e.printStackTrace();
        }

    }
}
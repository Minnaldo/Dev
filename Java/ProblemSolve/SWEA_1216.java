import java.util.Scanner;
import java.io.*;

public class SWEA_1216 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);

            for (int tc = 1; tc <= 10; tc++) {
                int ans = 0;
                int tmpTc = sc.nextInt();
                int size = 100;
                String[] map = new String[size];
                // String str = sc.next();
                for (int i = 0; i < size; i++) {
                    map[i] = sc.next();
                }

                // 100 개의 string을 돈다
                for (String str : map) {
                    // 앞쪽 인덱스 고정
                    // 뒤에서부터 같은지 비교해온다
                    // 같으면 앞쪽 인덱스++, 뒤쪽인덱스--
                    // 위를 반복해오다 각 인덱스의 값이 다르면
                    // 회문일 조건 : 뒤 인덱스 == 앞 인덱스(짝수 자릿수 회문) || 뒤 인덱스 - 앞 인덱스 == 2 (홀수 자릿수 회문)
                    // 회문이 아니면 : 길이 체크 변수 0으로 초기화 / 앞쪽 인덱스를 기억하고 있는 변수 + 1 / 뒤쪽 인덱스 변수는 99로
                    for (int i = 0; i < size; i++) {
                        // i는 시작지점 인덱스
                        int start = i;
                        int len = 0;

                        // 뒤쪽을 가리키는 변수 j
                        for (int j = size - 1; j >= 0; j--) {
                            if (str.charAt(start) == str.charAt(j)) {
                                if (j == start) {
                                    // 홀수 길이 회문 발견
                                    int tmp = len * 2 + 1;
                                    ans = ans > tmp ? ans : tmp;
                                } else if (j - 1 == start) {
                                    // 짝수 길이 회문 발견
                                    int tmp = (len + 1) * 2;
                                    ans = ans > tmp ? ans : tmp;
                                } else {
                                    // 회문이 아니면
                                    len++;
                                    if (start <= j)
                                        start++;
                                }
                            } else {
                                len = 0;
                                start = i;
                                j = size-1;
                            }

                        }

                    }
                }
                // 세로열 탐색
                for (int k = 0; k < map.length; k++) {
                    for (int i = 0; i < size; i++) {
                        // i는 시작지점 인덱스
                        int start = i;
                        int len = 0;
                        // 뒤쪽을 가리키는 변수 j
                        for (int j = size - 1; j >= 0; j--) {
                            if (map[start].charAt(k) == map[j].charAt(k)) {
                                if (j - 1 == start) {
                                    // 짝수 길이 회문 발견
                                    int tmp = (len + 1) * 2;
                                    ans = ans > tmp ? ans : tmp;
                                } else if (j == start) {
                                    // 홀수 길이 회문 발견
                                    int tmp = len * 2 + 1;
                                    ans = ans > tmp ? ans : tmp;
                                } else {
                                    len++;
                                    if (start <= j)
                                        start++;
                                }
                            } else {
                                len = 0;
                                start = i;
                                j = size-1;
                            }

                        }
                    }
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
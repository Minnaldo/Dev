
/**
 *  SWEA_2001
 *  m * m 크기의 파리채를 내려쳤을 때, 가장 많은 파리가 죽을수 있는 공간을 찾아내는 문제
 */

import java.util.Scanner;

class swea_2001 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] map = new int[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = sc.nextInt();
                }
            }

            int limit = n - m + 1;

            for (int a = 0; a < limit; a++) {
                for (int b = 0; b < limit; b++) {
                    int sum = 0;
                    for (int i = a; i < a + m; i++) {
                        for (int j = b; j < b + m; j++) {
                            sum += map[i][j];
                        }
                    }

                    ans = ans > sum ? ans : sum;
                }
            }

            System.out.println("#" + tc + " " + ans);
        }
    }
}
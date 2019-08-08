import java.util.*;
import java.io.*;

/**
 *  * 실력이 다를 수가 있다. 모든 케이스가 다 같은 능력인 것이 아니다.
 *
 */

public class SWEA_8104 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int cnt = 1;

            int[][] map = new int[n][k];
            int y = 0, x = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    map[i][j + (k - 1 - 2 * j) * (i % 2)] = cnt++;
                }
            }

            System.out.print("#" + tc);
            for (int i = 0; i < k; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    sum += map[j][i];
                }
                System.out.print(" " + sum);
            }
        }
        sc.close();
    }
}
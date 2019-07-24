/**
 *  * 원래는 재귀함수를 이용하여 풀 수 있는 문제, 이를 비트마스크를 이용해 조합을 찾아 해결한다.
 */

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA_5215 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;

            int n = sc.nextInt();
            int limit = sc.nextInt();

            int[] taste = new int[n];
            int[] cal = new int[n];

            for (int i = 0; i < n; i++) {
                taste[i] = sc.nextInt();
                cal[i] = sc.nextInt();
            }

            int setSize = 1 << n;

            int[] ansTaste = new int[setSize];
            int[] ansCal = new int[setSize];

            for (int i = 0; i < setSize; i++) {
                for (int j = 0; j < n; j++) {
                    if (((1 << j) & i) != 0) {
                        ansTaste[i] += taste[j];
                        ansCal[i] += cal[j];
                    }
                }
            }

            for (int i = 0; i < setSize; i++) {
                if (ansCal[i] <= limit) {
                    ans = ans > ansTaste[i] ? ans : ansTaste[i];
                }
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
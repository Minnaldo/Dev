/**
 *  * 배열의 인덱스를 이용해서 접근한다.
 */

import java.util.Scanner;

public class SWEA_1959 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt();
            int m = sc.nextInt();

            int[] arr = new int[n];
            int[] arr2 = new int[m];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                arr2[i] = sc.nextInt();
            }

            int max = n > m ? n : m;
            int min = n < m ? n : m;

            // 둘중 큰 얘
            int[] maxArr = max == n ? arr : arr2;
            // 둘중 작은 얘
            int[] minArr = min == n ? arr : arr2;

            int mvidx = max - min;
            for (int i = 0; i <= mvidx; i++) {
                int tmpSum = 0;
                for (int j = 0; j < min; j++) {
                    tmpSum += maxArr[j + i] * minArr[j];
                }
                ans = ans > tmpSum ? ans : tmpSum;
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
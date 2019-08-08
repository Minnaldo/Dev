/**
 *
 *  * 곱의 합과 합의 곱은 같을까?
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

            int[] A = new int[n];
            int[] B = new int[m];

            for (int i = 0; i < n; i++) {
                A[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                B[i] = sc.nextInt();
            }

            int mvidx = Math.abs(m-n);

            for(int i = 0; i<mvidx; i++){

            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
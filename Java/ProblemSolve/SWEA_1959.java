
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

            int max = n > m ? n : m;
            int min = n < m ? n : m;

            int[] A = new int[max];
            int[] B = new int[min];

            for (int i = 0; i < max; i++) {
                A[i] = sc.nextInt();
            }
            for (int i = 0; i < min; i++) {
                B[i] = sc.nextInt();
            }


            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
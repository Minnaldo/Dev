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

            int[] A = new int[n];
            int[] B = new int[m];

            int[] A = new int[max];
            int[] B = new int[min];

            for (int i = 0; i < max; i++) {
                A[i] = sc.nextInt();
            }
            for (int i = 0; i < min; i++) {
                B[i] = sc.nextInt();
            }

            int mvidx = max - min;

            for (int i = 0; i <= mvidx; i++) {
                int tmpSum = 0;
                for (int idx = i; idx < mvidx + i; idx++) {
                    tmpSum += A[idx] + B[idx];
                }
                ans = ans > tmpSum ? ans : tmpSum;
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
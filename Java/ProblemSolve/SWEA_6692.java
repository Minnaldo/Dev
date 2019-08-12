import java.util.Scanner;

/**
 *  다솔이의 월급상자
 */

public class SWEA_6692 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            double ans = 0.0;

            int n = sc.nextInt();

            for (int i = 0; i < n; i++) {
                double tmp = sc.nextDouble();
                int tmp2 = sc.nextInt();
                ans += (tmp * tmp2);
            }

            System.out.printf("#%d %.6f", tc, ans);
        }

        sc.close();
    }
}
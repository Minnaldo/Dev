import java.util.Scanner;

public class SWEA_1948 {

    static int[] perDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int m1 = sc.nextInt(), d1 = sc.nextInt(), m2 = sc.nextInt(), d2 = sc.nextInt();

            if (m1 != m2) {
                ans = perDay[m1] - d1 + d2 + 1;
                for (int i = m1 + 1; i < m2; i++) {
                    ans += perDay[i];
                }
            } else {
                ans = d2 - d1 + 1;
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
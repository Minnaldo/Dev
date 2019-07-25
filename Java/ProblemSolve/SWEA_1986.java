import java.util.*;

public class SWEA_1986 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt();

            for (int i = 1; i <= n; i++) {
                if (i % 2 == 0)
                    ans -= i;
                else
                    ans += i;
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
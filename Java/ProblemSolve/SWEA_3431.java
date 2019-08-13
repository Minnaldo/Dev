import java.util.*;

public class SWEA_3431 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int l = sc.nextInt(), u = sc.nextInt(), x = sc.nextInt();

            if (x < l) {
                ans = l - x;
            } else if (x > u) {
                ans = -1;
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
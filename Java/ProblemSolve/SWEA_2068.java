import java.util.*;

public class SWEA_2068 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;

            for (int i = 0; i < 10; i++) {
                int num = sc.nextInt();
                ans = ans > num ? ans : num;
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
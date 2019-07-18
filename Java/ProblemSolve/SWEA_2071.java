import java.util.Scanner;

public class SWEA_2071 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            double ans = 0.0;

            for (int i = 0; i < 10; i++) {
                ans += sc.nextInt();
            }

            System.out.println("#" + tc + " " + Math.round(ans/10.0));
        }
        sc.close();
    }
}
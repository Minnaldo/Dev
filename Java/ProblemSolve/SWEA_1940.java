import java.util.Scanner;

public class SWEA_1940 {
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = sc.nextInt();
                int speed = 0;

                for (int i = 0; i < n; i++) {
                    int sw = sc.nextInt();
                    int tmp = 0;
                    if (sw == 1) {
                        // 가속
                        tmp = sc.nextInt();
                        speed += tmp;
                    } else if (sw == 2) {
                        // 감속
                        tmp = sc.nextInt();
                        speed = speed < tmp ? 0 : speed - tmp;
                    }
                    ans += speed;
                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
    }
}
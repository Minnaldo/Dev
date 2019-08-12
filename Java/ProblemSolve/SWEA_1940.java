import java.io.FileInputStream;
import java.util.Scanner;

/**
 * 가랏 RC 카! 가속도와 속도의 관계?
 */

public class SWEA_1940 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = sc.nextInt();
                int speed = 0;

                for (int i = 0; i < n; i++) {
                    int sw = sc.nextInt(), tmp = sc.nextInt();
                    if (sw == 1) {
                        // 가속
                        speed += tmp;
                    } else if (sw == 2) {
                        // 감속
                        speed = speed < tmp ? 0 : speed - tmp;
                    }
                    ans += speed;
                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.util.Scanner;

public class SWEA_1284 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;

            int p = sc.nextInt(), q = sc.nextInt(), r = sc.nextInt(), s = sc.nextInt(), w = sc.nextInt();
            int comA = 0, comB = 0;

            comA = p * w;

            if (w <= r) {
                comB = q;
            } else {
                comB = q + ((w - r) * s);
            }

            ans = comA < comB ? comA : comB;

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
import java.util.Scanner;

public class SWEA_5601 {
    static int p, q;

    public static void gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        p = a;
        q = b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            p = 0;
            q = 0;
            int n = sc.nextInt();
            System.out.println("#" + tc + " " + p + "/" + q);
        }
        sc.close();
    }
}
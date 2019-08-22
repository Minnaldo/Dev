import java.util.Scanner;

public class SWEA_5601 {
    // static int p, q;

    // public static void gcd(int a, int b) {
    // while (b != 0) {
    // int r = a % b;
    // a = b;
    // b = r;
    // }
    // p = a;
    // q = b;
    // }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append("1/" + n).append(" ");
            }

            System.out.println("#" + tc + " " + sb.toString().trim());
        }
        sc.close();
    }
}
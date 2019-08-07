import java.util.Scanner;

//TODO
// 왜 틀리는 걸까?

public class SWEA_8104 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int k2 = k * 2;
            int sum = 0;

            for (int i = 1; i <= n; i++) {
                if (i % 2 == 0) {
                    sum += (k2 * (i / 2));
                } else {
                    sum += (k2 * (i / 2) + 1);
                }
            }
            System.out.print("#" + tc);
            for (int i = 0; i < k; i++)
                System.out.print(" " + sum);
        }
        sc.close();
    }
}
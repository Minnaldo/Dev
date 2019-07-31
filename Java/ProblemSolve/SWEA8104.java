import java.util.Scanner;

public class SWEA8104 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            if (n == 1) {
                System.out.print("#" + tc + " ");
                for (int i = 1; i < k; i++) {
                    System.out.print(i + " ");
                }
                System.out.println(k);
            } else {
                int sum = 0;
                for (int a = 1; a <= n; a += 2) {
                    if (a == 1) {
                        sum += 1;
                    } else if (a == 3) {
                        sum += (2 * k);
                    } else {
                        sum += k;
                    }
                }
                int tmpSum = 0;
                int cnt = 2;
                for (int a = 2; a <= n; a += 2) {
                    tmpSum += (cnt++ * k);
                }
                sum += tmpSum;

                System.out.println(sum + "\t" + tmpSum);

                System.out.print("#" + tc + " ");
                for (int i = 0; i < k - 1; i++) {
                    System.out.print(sum + " ");
                }
                System.out.println(sum);
            }

        }
        sc.close();
    }
}
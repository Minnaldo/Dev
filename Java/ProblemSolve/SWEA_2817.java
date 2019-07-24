import java.util.Scanner;

public class SWEA_2817 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;

            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();

            for (int i = 0; i < (1 << n); i++) {
                int tmpSum = 0;
                for (int j = 0; j < n; j++) {
                    if (((1 << j) & i) != 0) {
                        tmpSum += arr[j];
                    }
                }

                if (tmpSum == k)
                    ans++;
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
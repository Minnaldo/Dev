import java.util.Scanner;

/**
 * * 퍼펙트 셔플
 */

public class SWEA_3499 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt(); // 카드의 수
            String[] arr = new String[n];
            StringBuilder ans = new StringBuilder();

            for (int i = 0; i < n; i++) {
                arr[i] = sc.next();
            }

            if (n % 2 == 0) {
                // 짝수
                for (int i = 0; i < n / 2; i++) {
                    ans.append(arr[i] + " ");
                    ans.append(arr[n / 2 + i] + " ");
                }
            } else {
                for (int i = 0; i < n / 2; i++) {
                    ans.append(arr[i] + " ");
                    ans.append(arr[(n / 2 + 1) + i] + " ");
                }
                ans.append(arr[n / 2]);
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
import java.util.Scanner;

public class SWEA_2817_2 {

    static int tmpans = 0;

    static void recur(int[] arr, int sum, int idx, int k) {
        if (idx == arr.length) {
            if (sum == k) {
                tmpans++;
            }
            return;
        }
        recur(arr, sum + arr[idx], idx + 1, k);
        recur(arr, sum, idx + 1, k);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            tmpans = 0;
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            recur(arr, 0, 0, k);
            // recur(arr, arr[0], 0, k);
            ans = tmpans;

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
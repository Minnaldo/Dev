import java.io.*;
import java.util.*;

public class SWEA_4466 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            Arrays.sort(arr);

            System.out.println(Arrays.toString(arr));

            for (int i = n - 1; k > 0; i--, k--) {
                ans += arr[i];
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
import java.io.*;
import java.util.*;

public class DP_practice2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long[] dp = new long[n + 2];

        dp[0] = 0;
        dp[1] = 2;
        dp[2] = 5;

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2) + dp[i - 2];
        }

        System.out.println(dp[n]);
    }
}
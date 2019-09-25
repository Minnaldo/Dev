import java.io.*;
import java.util.*;

/**
 * 이항계수
 */

public class DP_Practice4 {
    static long[][] memo;
    static long[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        memo = new long[n][n];
        dp = new long[n][n];
        System.out.println(bino(n, k));
        System.out.println(dp_bino(n, k));
    }

    static long bino(int n, int k) {
        if (memo[n][k] != 0)
            return memo[n][k];
        if (k == 0 || k == n) {
            return 1;
        }
        memo[n][k] = bino(n - 1, k) + bino(n - 1, k - 1);
        return memo[n][k];
    }

    static long dp_bino(int n, int k) {
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n][k];
    }
}
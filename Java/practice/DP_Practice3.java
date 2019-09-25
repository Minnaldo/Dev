import java.io.*;
import java.util.*;

/**
 * 동전 찾기
 */

public class DP_Practice3 {
    public static void main(String[] args) {
        int[] arr = { 1, 4, 6 };
        int n = 178;
        int[] dp = new int[n + 1];
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j < arr.length; j++) {
                if (i - arr[j] >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }

        System.out.println(dp[n]);

    }
}
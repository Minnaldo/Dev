import java.io.*;
import java.util.*;

/**
 * * 상향식과 하향식 dp 모두 사용하기 문제없는 상황이면 상향식의 성능이 더 좋다 (함수 콜 오버헤드가 없으므로)
 * * 점화식을 잘 뽑으면 문제풀기가 수월해진다
 */

public class Fibo {
    static int[] memo = new int[1000];

    // 하향식 DP
    // 다방면으로 함수콜이 일어나는 경우 사용하면 좋음
    public static int fibo(int n) {
        if (memo[n] != 0) {
            return memo[n];
        }

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        memo[n] = fibo(n - 1) + fibo(n - 2);
        return memo[n];
    }

    // 상향식 DP
    static int fibo_dp(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(fibo(sc.nextInt()));
    }
}
import java.io.*;
import java.util.*;

public class DP_Practice5 {
    static long[][] dp = new long[4][200];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = 1;


    }
}
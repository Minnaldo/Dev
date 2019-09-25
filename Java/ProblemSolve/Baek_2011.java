import java.io.*;
import java.util.*;

public class Baek_2011 {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int[] dp = new int[str.length() + 1];
        dp[1] = 1;
        if (Integer.parseInt(str.substring(0, 2)) <= 26) {
            dp[2] = 1;
        }

        for (int i = 3; i <= str.length(); i++) {
            if()
            dp[i] += dp[i-1];
            if (Integer.parseInt(str.substring(i-1, i+1)) <= 26) {
                dp[i] += dp[i-2];
            }
        }
    }
}
import java.io.*;
import java.math.BigInteger;
import java.util.*;

/** 타일링_백준
 *
 */

public class Baek_1793 {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger[] memo = new BigInteger[252];
        memo[0] = BigInteger.ZERO;
        memo[1] = BigInteger.ONE;
        memo[2] = new BigInteger("3", 10);
        BigInteger mul = new BigInteger("2", 10);
        for (int i = 2; i <= 251; i++) {
            memo[i] = memo[i - 2].multiply(mul).add(memo[i - 1]);
        }

        while (true) {
            try {
                int n = Integer.parseInt(br.readLine());
                System.out.println(memo[n + 1].toString(10));
            } catch (Exception e) {
                return;
            }
        }
    }
}
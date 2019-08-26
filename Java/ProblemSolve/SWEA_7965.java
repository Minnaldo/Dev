import java.io.*;
import java.math.BigInteger;

public class SWEA_7965 {
    static long pow(long x, long y) {
        if (y == 1) {
            return x;
        }
        if (y == 0) {
            return 1;
        }

        if (y % 2 == 0) {
            // 짝수
            long tmp = pow(x, y / 2);
            return (tmp * tmp)%1000000007;
        } else {
            // 홀수
            long tmp = pow(x, (y - 1) / 2);
            return (tmp * tmp * x)%1000000007;
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int n = Integer.parseInt(br.readLine());
                BigInteger bi = new BigInteger("1");
                for (int i = 2; i <= n; i++) {
                    // ans += (pow(i, i));
                    bi = bi.add(BigInteger.valueOf((pow(i, i))));
                    bi = bi.mod(BigInteger.valueOf(1000000007));
                }

                bi = bi.mod(BigInteger.valueOf(1000000007));

                System.out.println("#" + tc + " " + bi.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
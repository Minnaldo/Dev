import java.io.*;
import java.math.BigInteger;

public class SWEA_3260 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                String[] input = br.readLine().split(" ");

                BigInteger b1 = new BigInteger(input[0]);
                BigInteger b2 = new BigInteger(input[1]);

                b1 = b1.add(b2);

                System.out.println("#" + tc + " " + b1.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
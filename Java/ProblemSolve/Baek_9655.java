import java.io.*;

/**
 *  돌 게임
 */

public class Baek_9655 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            boolean flag = false;
            while (n > 0) {
                if (n - 3 >= 0) {
                    n -= 3;
                } else if (n - 1 >= 0) {
                    n -= 1;
                }
                flag = !flag;
            }

            String str = "SK";

            if (!flag) {
                str = "CY";
            }

            System.out.println(str);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.util.StringTokenizer;

/**
 * 두가지 빵의 딜레마
 */

public class SWEA_5162 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;

                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                ans = c / (a + b);
                ans = ans > c / a ? ans : c / a;
                ans = ans > c / b ? ans : c / b;

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
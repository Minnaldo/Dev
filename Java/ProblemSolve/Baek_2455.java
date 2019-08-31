import java.io.*;
import java.util.StringTokenizer;

public class Baek_2455 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = null;
            int sum = 0, ans = 0;
            for (int i = 0; i < 4; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                sum = (b - a) + sum;
                ans = ans > sum ? ans : sum;
            }
            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
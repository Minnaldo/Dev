import java.io.*;

public class SWEA_7728 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = Integer.parseInt(br.readLine());
                boolean[] arr = new boolean[10];
                while (n > 0) {
                    arr[n % 10] = true;
                    n /= 10;
                }

                for (boolean bb : arr) {
                    if (bb)
                        ans++;
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
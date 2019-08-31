import java.io.*;
import java.util.StringTokenizer;

public class SWEA_6913 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());
                int[] arr = new int[n];

                int maxPro = 0;
                for (int i = 0; i < n; i++) {
                    st = new StringTokenizer(br.readLine());
                    while (st.hasMoreTokens()) {
                        arr[i] += Integer.parseInt(st.nextToken());
                    }
                    maxPro = Math.max(maxPro, arr[i]);
                }

                for (int i = 0; i < n; i++)
                    if (arr[i] == maxPro)
                        ans++;

                System.out.println("#" + tc + " " + ans + " " + maxPro);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
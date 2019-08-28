import java.io.*;
import java.util.StringTokenizer;

/**
 * 자기 방으로 돌아가기
 */

public class SWEA_4408 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine().trim());

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = Integer.parseInt(br.readLine().trim());

                int[] arr = new int[201];
                for (int i = 0; i < n; i++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    int a = Integer.parseInt(st.nextToken());
                    int b = Integer.parseInt(st.nextToken());

                    a = (a + 1) / 2;
                    b = (b + 1) / 2;

                    int left = a > b ? b : a;
                    int right = a > b ? a : b;

                    for (int j = left; j <= right; j++) {
                        arr[j]++;
                        ans = Math.max(arr[j], ans);
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
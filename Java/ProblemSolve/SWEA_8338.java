import java.io.*;
import java.util.StringTokenizer;

/**
 *  계산기
 */

public class SWEA_8338 {

    static int ans;

    static void func(int[] arr, int sum, int idx) {
        if (idx == arr.length) {
            ans = ans > sum ? ans : sum;
            return;
        }

        func(arr, sum + arr[idx], idx + 1);
        func(arr, sum * arr[idx], idx + 1);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ans = 0;
                int aa = Integer.parseInt(br.readLine());
                StringTokenizer st = new StringTokenizer(br.readLine());
                int[] arr = new int[aa];

                for (int i = 0; i < aa; i++) {
                    arr[i] = Integer.parseInt(st.nextToken());
                }
                func(arr, 0, 0);
                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
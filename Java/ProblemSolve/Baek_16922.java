import java.io.*;

/**
 *  로마 숫자 만들기
 */

public class Baek_16922 {

    static int n, ans;
    static int[] arr = { 1, 5, 10, 50 };
    static boolean[] visit;

    static void recur(int idx, int sum, int num) {

        if (idx == n) {
            if (visit[sum])
                return;
            visit[sum] = true;
            ans++;
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (arr[i] >= num)
                recur(idx + 1, sum + arr[i], arr[i]);
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine());
            ans = 0;
            visit = new boolean[1001];
            for (int i = 0; i < 4; i++)
                recur(0, 0, arr[i]);
            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
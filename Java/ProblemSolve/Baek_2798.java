import java.io.*;
import java.util.StringTokenizer;

public class Baek_2798 {

    static int ans, m, n;

    static void func(int[] arr, int sum, int idx, boolean[] visit) {
        if (idx == 3) {
            if (sum <= m)
                ans = ans > sum ? ans : sum;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                func(arr, sum + arr[i], idx + 1, visit);
                visit[i] = false;
            }
        }

    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            ans = 0;
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            int[] arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            func(arr, 0, 0, new boolean[n]);

            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
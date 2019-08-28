import java.io.*;
import java.util.*;

public class Baek_16922 {

    static int n, ans;
    static int[] arr = { 1, 5, 10, 50 };

    // static HashSet<Integer> set;
    static boolean[] visit;

    static void recur(int idx, int sum, int num) {

        if (idx == n) {
            visit[sum] = true;
            ans++;
            return;
        }

        // for (int i = 0; i < 4; i++) {
        // if (!visit[sum + arr[i]]) {
        // recur(idx + 1, sum + arr[i], arr[i]);
        // }
        // }

        if (num >= 50) {
            if (!visit[sum + 50])
                recur(idx + 1, sum + 50, num);
        }
        if (num >= 10) {
            if (!visit[sum + 10])
                recur(idx + 1, sum + 10, num);
        }
        if (num >= 5) {
            if (!visit[sum + 5])
                recur(idx + 1, sum + 5, num);
        }
        if (!visit[sum + 1])
            recur(idx + 1, sum + 1, num);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                n = Integer.parseInt(br.readLine());
                ans = 0;
                // set = new HashSet<>();
                visit = new boolean[20 * 50 + 1];
                // set.add(1);
                for (int i = 0; i < 3; i++)
                    recur(0, 0, arr[i]);
                // ans = set.size();
                System.out.println(ans);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
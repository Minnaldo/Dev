import java.io.*;
import java.util.*;

public class Baek_16922 {

    static int n;
    static int[] arr = { 1, 5, 10, 50 };
    static HashSet<Integer> set;

    static void recur(int idx, int sum, int num) {

        if (idx == n) {
            set.add(sum);
            return;
        }
// TODO : need backtarck
        if (num >= 50) {
            recur(idx + 1, sum + 50, num);
        }
        if (num >= 10) {
            recur(idx + 1, sum + 10, num);
        }
        if (num >= 5) {
            recur(idx + 1, sum + 5, num);
        }
        recur(idx + 1, sum + 1, num);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine());
            int ans = 0;
            // arr = new int[21][4];
            set = new HashSet<>();

            for (int i = 0; i < 4; i++)
                recur(0, 0, arr[i]);
            ans = set.size();
            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
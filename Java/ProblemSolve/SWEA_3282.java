import java.io.*;
import java.util.*;

// k이하 부피의 최대가치
// TODO timeout
// 가지치기가 필요할꺼같은데?

public class SWEA_3282 {

    static int k;
    static int ans;
    static int n;

    public static void recur(int[] vol, int[] cost, int volume, int sum, int idx) {

        if (idx == n || volume > k) {
            return;
        }

        if (volume <= k) {
            ans = ans > sum ? ans : sum;
        }

        recur(vol, cost, volume + vol[idx], sum + cost[idx], idx + 1);
        recur(vol, cost, volume, sum, idx + 1);
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                ans = 0;

                n = sc.nextInt();
                k = sc.nextInt();

                int[] vol = new int[n];
                int[] cost = new int[n];

                for (int i = 0; i < n; i++) {
                    vol[i] = sc.nextInt();
                    cost[i] = sc.nextInt();
                }

                recur(vol, cost, 0, 0, 0);

                System.out.println("#" + tc + " " + ans);
            }
            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
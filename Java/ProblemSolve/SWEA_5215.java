import java.io.*;

/**
 *  햄버거 다이어트
 */

public class SWEA_5215 {

    static int ans, l;

    static void recur(int[] taste, int[] cal, int tt, int cc, int idx) {

        if (cc > l) {
            return;
        } else {
            ans = ans > tt ? ans : tt;
        }

        if (idx == taste.length) {
            return;
        }

        recur(taste, cal, tt + taste[idx], cc + cal[idx], idx + 1);
        recur(taste, cal, tt, cc, idx + 1);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ans = 0;
                String[] input = br.readLine().split(" ");
                int n = Integer.parseInt(input[0]);
                l = Integer.parseInt(input[1]);

                int[] m = new int[n];
                int[] cal = new int[n];

                for (int i = 0; i < n; i++) {
                    input = br.readLine().split(" ");
                    m[i] = Integer.parseInt(input[0]);
                    cal[i] = Integer.parseInt(input[1]);
                }

                recur(m, cal, 0, 0, 0);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
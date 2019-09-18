import java.io.*;
import java.util.*;

public class SWEA_7465 {
    static int n, m, ans;
    static int[] parents;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                ans = 0;
                n = Integer.parseInt(st.nextToken());
                m = Integer.parseInt(st.nextToken());
                parents = new int[n + 1];
                for (int i = 1; i <= n; i++) {
                    parents[i] = i;
                }

                for (int i = 0; i < m; i++) {
                    st = new StringTokenizer(br.readLine());
                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());
                    union(x, y);
                }

                for (int i = 1; i <= n; i++) {
                    if (i == parents[i]) {
                        ans++;
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void union(int x, int y) {
        int py = findSet(y);
        int px = findSet(x);
        parents[py] = px;
    }

    static int findSet(int x) {
        if (x == parents[x])
            return x;
        parents[x] = findSet(parents[x]);
        return parents[x];
    }
}
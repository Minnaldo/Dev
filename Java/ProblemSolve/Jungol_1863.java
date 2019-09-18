import java.io.*;
import java.util.StringTokenizer;

public class Jungol_1863 {
    static int n, m, ans;
    static int[] parents, rank;

    /*
     * 랭크 구현 원소의 수만큼 rank배열 생성
     *
     */

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ans = 0;
        parents = new int[n + 1];
        rank = new int[n + 1];
        // make-set
        for (int i = 1; i <= n; i++)
            parents[i] = i;

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            union(x, y);
        }

        for (int i = 1; i <= n; i++) {
            if (i == parents[i])
                ans++;
        }

        System.out.println(ans);
    }

    static void union(int x, int y) {
        int px = find_set(x);
        int py = find_set(y);
        // parents[py] = px;

        if (rank[px] < rank[py]) {
            parents[px] = py;
        } else {
            parents[py] = px;
            if (rank[py] == rank[px])
                rank[px]++;
        }
    }

    static int find_set(int x) {
        if (parents[x] == x) {
            return x;
        }
        parents[x] = find_set(parents[x]);
        return parents[x];
    }
}
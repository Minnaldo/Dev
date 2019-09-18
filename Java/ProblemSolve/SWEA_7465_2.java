import java.io.*;
import java.util.*;

/*
랭크를 사용하자
*/

/* 랭크를 사용할 때 규칙
1. 랭크가 같은 노드들을 붙일 때 : 랭크값에 + 1
2. 랭크가 다른 노드들을 붙일 때 : 랭크값이 큰 노드에, 랭크값이 작은 노드를 붙인다
 */

public class SWEA_7465_2 {
    static int n, m, ans;
    static int[] parents, rank;// 랭크를 저장할 배열

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("./input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                ans = 0;
                n = Integer.parseInt(st.nextToken());
                m = Integer.parseInt(st.nextToken());
                parents = new int[n + 1];
                rank = new int[n + 1];
                boolean[] visit = new boolean[n + 1];
                for (int i = 1; i <= n; i++) {
                    parents[i] = i;
                }

                for (int i = 0; i < m; i++) {
                    st = new StringTokenizer(br.readLine());
                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());
                    union(x, y);
                }

                // for (int i = 1; i <= n; i++) {
                // if (i == parents[i]) {
                // ans++;
                // }
                // }

                for (int i = 1; i <= n; i++) {
                    if (!visit[rank[i]]) {
                        visit[rank[i]] = true;
                        ans++;
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 랭크를 이용해 붙일 지점
    static void union(int x, int y) {
        int py = findSet(y);
        int px = findSet(x);
        // parents[py] = px;

        if (rank[py] > rank[px]) {
            parents[px] = py;
            rank[px] = rank[py];
        } else {
            if (rank[py] == rank[px]) {
                parents[py] = px;
                rank[px]++;
            } else {
                parents[px] = py;
                rank[py] = rank[px];
            }
        }

    }

    static int findSet(int x) {
        if (x == parents[x])
            return x;
        parents[x] = findSet(parents[x]);
        return parents[x];
    }
}
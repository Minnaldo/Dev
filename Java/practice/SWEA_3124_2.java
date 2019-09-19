import java.io.*;
import java.util.*;

/**
 * * Prim version
 * * 정점의 갯수보다 간선의 갯수가 작아서 prim을 이용할 경우 오래걸리게 된다
 */

public class SWEA_3124_2 {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            long ans = 0L;
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            ArrayList<Edge>[] list = new ArrayList[n + 1];
            boolean[] visit = new boolean[n + 1];
            for (int i = 1; i <= n; i++)
                list[i] = new ArrayList();

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int val = Integer.parseInt(st.nextToken());
                list[x].add(new Edge(y, val));
                list[y].add(new Edge(x, val));
            }
            PriorityQueue<Edge> pq = new PriorityQueue<>();
            int cnt = 1;
            visit[1] = true;
            pq.addAll(list[1]);
            while (cnt < n) {
                Edge e = pq.poll();
                if (visit[e.dest])
                    continue;
                pq.addAll(list[e.dest]);
                visit[e.dest] = true;
                cnt++;
                ans += e.val;
            }

            System.out.println("#" + tc + " " + ans);
        }
    }

    static class Edge implements Comparable<Edge> {
        int dest, val;

        Edge(int dest, int val) {
            this.dest = dest;
            this.val = val;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.val, o.val);
        }
    }
}
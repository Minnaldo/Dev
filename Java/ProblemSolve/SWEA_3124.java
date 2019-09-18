import java.io.*;
import java.util.*;

public class SWEA_3124 {
    static int[] parents;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            long ans = 0L;
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            parents = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                parents[i] = i;
            }
            ArrayList<Edge> list = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int val = Integer.parseInt(st.nextToken());
                list.add(new Edge(x, y, val));
            }
            Collections.sort(list, new Comparator<Edge>() {

                @Override
                public int compare(Edge o1, Edge o2) {
                    return o1.val - o2.val;
                }
            });

            int cnt = 0;
            for (int i = 0; i < list.size(); i++) {
                Edge e = list.get(i);
                if (find(e.x) != find(e.y)) {
                    ans += e.val;
                    uinion(e.x, e.y);
                }
                if (cnt == list.size() - 1) {
                    break;
                }
            }

            System.out.println("#" + tc + " " + ans);
        }
    }

    static void uinion(int x, int y) {
        parents[find(y)] = find(x);
    }

    static int find(int x) {
        int tmp = x;
        while (tmp != parents[tmp])
            tmp = parents[tmp];
        parents[x] = tmp;
        return tmp;
    }

    static class Edge {
        int x, y, val;

        Edge(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }
}
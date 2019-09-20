import java.io.*;
import java.util.*;

/**
*
*/

public class SWEA_1251_Kruskal {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            int n = Integer.parseInt(br.readLine());
            double E;
            double[][] island = new double[n][2];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++)
                island[i][1] = Double.parseDouble(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++)
                island[i][0] = Double.parseDouble(st.nextToken());
            E = Double.parseDouble(br.readLine());

            int A = n * (n - 1) / 2;

            ArrayList<Edge> list = new ArrayList<>();
            // 지점 정보 만들기
            for (int i = 0; i < n; i++) {
                double x1 = island[i][1];
                double y1 = island[i][0];
                for (int j = i + 1; j < n; j++) {
                    double x2 = island[j][1];
                    double y2 = island[j][0];
                    double tmpCost = E * (Math.pow((y2 - y1), 2) + Math.pow((x2 - x1), 2));
                    list.add(new Edge(i, j, tmpCost));
                    list.add(new Edge(j, i, tmpCost));
                }
            }

            double ret = 0.0;
            parents = new int[list.size()];

            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
            Collections.sort(list, new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return Double.compare(o1.cost, o2.cost);
                }
            });
            int cnt = 0;
            for (int i = 0; i < list.size(); i++) {
                Edge e = list.get(i);

                if (find(e.src) != find(e.dest)) {
                    union(e.src, e.dest);
                    cnt++;
                    ret += e.cost;
                }

                if (cnt == n - 1)
                    break;
            }

            System.out.println("#" + tc + " " + (long) Math.round(ret));
        }
    }

    static int[] parents;

    static void union(int x, int y) {
        int py = parents[find(x)];
        int px = parents[find(y)];
        parents[py] = px;
    }

    static int find(int x) {
        if (x == parents[x])
            return x;
        return parents[x] = find(parents[x]);
    }

    static class Edge {
        int src, dest;
        double cost;

        Edge(int src, int dest, double cost) {
            this.src = src;
            this.dest = dest;
            this.cost = cost;
        }
    }
}

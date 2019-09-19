import java.io.*;
import java.util.*;

/**
* 
*/

public class SWEA_1251 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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

            ArrayList<Edge>[] list = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                list[i] = new ArrayList();
            }
            // 지점 정보 만들기
            for (int i = 0; i < n; i++) {
                double x1 = island[i][1];
                double y1 = island[i][0];
                for (int j = i + 1; j < n; j++) {
                    double x2 = island[j][1];
                    double y2 = island[j][0];
                    double tmpCost = E * (Math.pow((y2 - y1), 2) + Math.pow((x2 - x1), 2));
                    list[i].add(new Edge(j, tmpCost));
                    list[j].add(new Edge(i, tmpCost));
                }
            }

            PriorityQueue<Edge> pq = new PriorityQueue<>();
            pq.addAll(list[0]);

            boolean[] visit = new boolean[n];
            visit[0] = true;
            int cnt = 1;
            double ret = 0.0;
            while (cnt < n) {
                Edge tmp = pq.poll();

                if (visit[tmp.dest])
                    continue;
                pq.addAll(list[tmp.dest]);
                visit[tmp.dest] = true;
                cnt++;
                ret += tmp.cost;
            }

            System.out.println("#" + tc + " " + (Long) Math.round(ret));
        }
    }

    static class Edge implements Comparable<Edge> {
        int dest;
        double cost;

        Edge(int dest, double cost) {
            this.dest = dest;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return Double.compare(this.cost, o.cost);
        }
    }
}

import java.io.*;
import java.util.*;

/*
최단경로
다익스트라 알고리즘을 이용한 문제
*/

public class Baek_1753 {
    static int inf = 987654321;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine());
        int[][] map = new int[v + 1][v + 1];
        ArrayList<Edge>[] list = new ArrayList[v + 1];
        for (int i = 1; i <=v; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            // map[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
            list[Integer.parseInt(st.nextToken())].add(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        int[] dst = new int[v + 1];
        boolean[] visit = new boolean[v + 1];
        visit[start] = true;
        for (int i = 0; i < list[start].size(); i++) {
            dst[i] = list[start].get(i).cost;
            dst[i] = dst[i] == 0 ? inf : dst[i];
        }

        for (int i = 1; i <= v; i++) {
            if (i != start) {
                int min = inf;
                int minIdx = 0;

                for (int j = 1; j <= v; j++) {
                    if (!visit[j] && min > dst[j]) {
                        min = dst[j];
                        minIdx = j;
                    }
                }

                for (int j = 0; j < list[minIdx].size(); j++) {
                    if (list[minIdx].get(j).cost > 0 && !visit[j]) {
                        dst[list[minIdx].get(j).dst] = Math.min(dst[j], dst[minIdx] + list[minIdx].get(j).cost);
                    }
                }
                visit[minIdx] = true;
            }
        }

        dst[start] = 0;
        for (int i = 1; i <= v; i++) {
            System.out.println(dst[i] == 987654321 ? "INF" : dst[i]);
        }
    }

    static class Edge {
        int dst, cost;

        Edge(int dst, int cost) {
            this.dst = dst;
            this.cost = cost;
        }
    }
}

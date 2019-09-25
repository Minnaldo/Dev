import java.io.*;
import java.util.*;

/**
 * *최단경로 * 다익스트라 알고리즘을 이용한 문제 -> 인접행렬 이용시 메모리초과 ( 노드의 수가 많다 ) -> 인접 리스트로 해결 *
 * 개선: 우선순위 큐를 이용해 속도를 증가시킬 수 있다.
 */

public class Baek_1753 {
    static int inf = 987654321;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine());

        ArrayList<Edge>[] list = new ArrayList[v + 1];
        // 인접리스트 초기화
        for (int i = 0; i <= v; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            list[Integer.parseInt(st.nextToken())]
                    .add(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        // i번째 정점까지의 최단거리를 저장하는 배열
        int[] dst = new int[v + 1];
        boolean[] visit = new boolean[v + 1];
        // 비용 배열 무한대로 초기화
        for (int i = 0; i < dst.length; i++) {
            dst[i] = inf;
        }
        dst[start] = 0;
        // 다익스트라 시작
        for (int i = 1; i <= v; i++) {
            int min = inf;
            int minIdx = 0;
            // 지금까지 저장된 경로의 비용 중, 가장 비용이 작은 경로를 찾는다
            for (int j = 1; j <= v; j++) {
                if (!visit[j] && min > dst[j]) {
                    min = dst[j];
                    minIdx = j;
                }
            }

            // 지금까지 지나온 경로의 비용 중 가장 작은 곳에서, 다음 갈길을 찾는다
            // 지금까지의 비용 + 현 지점에서 다음 목적지로 가는 비용이
            // 목적지로 가는 비용보다 작으면 갱신
            for (int j = 0; j < list[minIdx].size(); j++) {
                if (list[minIdx].get(j).cost != 0 && !visit[list[minIdx].get(j).dst]) {
                    dst[list[minIdx].get(j).dst] = Math.min(dst[list[minIdx].get(j).dst],
                            dst[minIdx] + list[minIdx].get(j).cost);
                }
            }
            visit[minIdx] = true;
        }
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

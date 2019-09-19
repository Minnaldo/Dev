import java.io.*;
import java.util.*;

/* 간선의 정보는 간선리스트로 관리하는게 좋다
간선리스트의 간선 정보는 도착지와 경로비용으로 이뤄진 자료구조
각 정점별로 간선리스트를 갖고 있음

효율적으로 짜려면 우선순위 큐(최소/최대 힙)를 이용한다
 */

public class Prim_Algorithm {
    static ArrayList<Edge>[] list;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("kruska_input.txt")));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        list = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            list[i] = new ArrayList();
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.value - o2.value;
            }
        });

        // 간선리스트를 만든다 ( 인접리스트 )
        // 각 정점별로 리스트를 하나씩 갖고있어야 하고
        // 각 리스트에는 도착정점+경로비용의 정보가 있어야 함
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());
            // 양방향 정점이다!
            list[start].add(new Edge(end, value));
            list[end].add(new Edge(start, value));
        }
        for (int i = 0; i < n; i++) {
            Collections.sort(list[i], new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return o1.end - o2.end;
                }
            });
        }

        // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < list[i].size(); j++) {
        // System.out.print(list[i].get(j).toString() + " ");
        // }
        // System.out.println();
        // }

        // 선택된 정점이 모여있는 곳
        ArrayList<Integer> selList = new ArrayList<>();
        // 선택된 정점을 표시하는 체크배열
        boolean[] visit = new boolean[n];

        // 아무거나 한 정점을 선택한다 (선택배열에 담고 체크배열에 체크)

        // 선택한 정점이 n개가 될때까지
        // 선택된 정점에서 출발하는 간선 중, 도착지가 선택되지 않은 정점이면서 가장 비용이 가장 작은 간선을 선택
        // 선택된 간선으로부터 연결되는 정점을 선택 (선택배열에 담고 체크배열에 체크)

        selList.add(0);
        visit[0] = true;
        int ans = 0;
        while (selList.size() < n) {
            // 최솟값
            int min = 987654321;
            int tmpDest = -1;

            // 선택되었던 모든 정점에서 검사를 해야한다
            // 선택되있는 정점을 하나씩 꺼내서
            for (int v : selList) {
                // 각 정점별로 간선 리스트를 모두 검사
                for (int i = 0; i < list[v].size(); i++) {
                    Edge edge = list[v].get(i);
                    if (!visit[edge.end] && min > edge.value) {
                        tmpDest = edge.end;
                        min = edge.value;
                    }
                }
            }

            visit[tmpDest] = true;
            ans += min;
            selList.add(tmpDest);
        }

        System.out.println("모든 정점을 잊는 최소 비용은 : " + ans + " 입니다");

    }

    static class Edge {
        int end, value;

        Edge(int end, int value) {
            this.end = end;
            this.value = value;
        }

        @Override
        public String toString() {
            return "[" + " end=" + end + ", value=" + value + " ]";
        }
    }
}
import java.io.*;
import java.util.*;

public class Prim_pq_Algorithm {

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

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());
            // 양방향 정점이다!
            list[start].add(new Edge(end, value));
            list[end].add(new Edge(start, value));
        }

        // 정점을 선택한다는 것은, 해당정점으로부터 뻗어나가는 모든 간선을 우선순위큐에 넣는것
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] visit = new boolean[n];

        // 0번 정점을 선택하는 코드
        int cnt = 1; // 선택된 정점의 갯수
        visit[0] = true;
        pq.addAll(list[0]); // 0번 리스트에 있는 간선 정보를 모두 넣음
        int ans = 0;
        while (cnt < n) {
            // 가장 작은비용의 간선
            Edge e = pq.poll();
            // 이미 방문한 정점이 나오면 패스
            if (visit[e.end])
                continue;
            // e.end목적지 간선을 선택
            pq.addAll(list[e.end]);
            visit[e.end] = true;
            cnt++;
            ans += e.value;
        }

        System.out.println("모든 정점을 잊는 최소 비용은 : " + ans + " 입니다");

    }

    static class Edge implements Comparable<Edge> {
        int end, value;

        Edge(int end, int value) {
            this.end = end;
            this.value = value;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.value, o.value);
        }

        @Override
        public String toString() {
            return "[" + " end=" + end + ", value=" + value + " ]";
        }
    }
}
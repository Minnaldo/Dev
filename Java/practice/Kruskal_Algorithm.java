import java.io.*;
import java.util.*;

/* kruskal algorithm */

/*
각 정점에 해당하는 상호배타집합(Union-Find)을 준비 ( 처음엔 각 정점이 하나의 집합 )
간선을 경로비용순으로 오름차순 정렬하고
첫번째 간선부터 반복해서 검사
두 정점이 같은 집합인지 확인
아니면 간선을 선택, Union
같은 집합이라면 다음 간선으로 이동
N-1개의 간선을 선택하면 종료
 */

public class Kruskal_Algorithm {

    static int[] parents;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("kruska_input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            parents = new int[n];
            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
            ArrayList<Edge> list = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                int value = Integer.parseInt(st.nextToken());
                list.add(new Edge(start, end, value));
            }

            Collections.sort(list, new Comparator<Edge>() {
                @Override
                public int compare(Edge o1, Edge o2) {
                    return o1.value - o2.value;
                }
            });

            int cnt = 0;
            int ans = 0;
            for (int i = 0; i < list.size(); i++) {
                Edge e = list.get(i);
                if (find_set(e.start) != find_set(e.end)) {
                    union(e.start, e.end);
                    cnt++;
                    ans += e.value;
                }

                if (cnt == n - 1)
                    break;
            }

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void union(int x, int y) {
        int py = parents[find_set(y)];
        int px = parents[find_set(x)];
        parents[py] = px;
    }

    static int find_set(int x) {
        if (parents[x] == x)
            return x;
        parents[x] = find_set(parents[x]);
        return parents[x];
    }

    static class Edge {
        int start, end, value;

        Edge(int start, int end, int value) {
            this.start = start;
            this.end = end;
            this.value = value;
        }
    }
}
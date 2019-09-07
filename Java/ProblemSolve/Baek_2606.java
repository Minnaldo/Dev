import java.io.*;
import java.util.*;

/**
 *  * 경로 맵이 주어졌을 때, 연결된 노드의 갯수를 찾는 문제
 */

public class Baek_2606 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int k = Integer.parseInt(br.readLine());
            StringTokenizer st;
            boolean[][] map = new boolean[n + 1][n + 1];
            boolean[] visit = new boolean[n + 1];
            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                map[a][b] = map[b][a] = true;
            }
            int ans = 0;

            Queue<Integer> q = new LinkedList<>();
            q.add(1);
            visit[1] = true;
            while (!q.isEmpty()) {
                int cur = q.poll();

                for (int i = 1; i <= n; i++) {
                    if (map[cur][i] && !visit[i]) {
                        q.add(i);
                        visit[i] = true;
                        map[cur][i] = map[i][cur] = false;
                        ans++;
                    }
                }
            }
            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
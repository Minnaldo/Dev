import java.io.*;
import java.util.*;

public class Baek_2206 {

    static int n, m, ans, len;
    static int[][] map, dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ans = 987654321;
        map = new int[n][m];
        boolean[][] visit = new boolean[n][m];
        // init
        for (int i = 0; i < n; i++) {
            char[] tmp = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                map[i][j] = Character.digit(tmp[j], 10);
            }
        }

        visit[0][0] = true;
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, 1, true));

        while (!q.isEmpty()) {
            Node node = q.poll();
            if (node.y == n - 1 && node.x == m - 1) {
                ans = Math.min(ans, node.cnt);
                break;
            }

            int tmpCnt = node.cnt;
            for (int i = 0; i < 4; i++) {
                int ny = node.y + dir[i][0];
                int nx = node.x + dir[i][1];

                if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
                    if (!visit[ny][nx]) {
                        if (map[ny][nx] == 0) {
                            visit[ny][nx] = true;
                            q.add(new Node(ny, nx, tmpCnt + 1, node.through));
                        } else {
                            if (node.through) {
                                visit[ny][nx] = true;
                                q.add(new Node(ny, nx, tmpCnt + 1, false));
                            }
                        }
                    }
                }
            }
        }

        ans = ans == 987654321 ? -1 : ans;
        System.out.println(ans);
    }

    static class Node {
        int y, x, cnt;
        boolean through;

        Node(int y, int x, int cnt, boolean through) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
            this.through = through;
        }
    }
}
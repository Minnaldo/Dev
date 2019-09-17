import java.io.*;
import java.util.*;

public class Baek_7569 {

    static int[][] dir = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, -1, 0 }, { 0, 0, -1 } };
    static int n, m, h, ans;
    static int[][][] map;
    static boolean[][][] visit;
    static Queue<Tomato> q;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        map = new int[h][m][n];
        visit = new boolean[h][m][n];
        q = new LinkedList<>();
        ans = 987654321;
        int total = (n * m) * h;
        int ripeCnt = 0, noTomato = 0;
        // input
        for (int i = 0; i < h; i++) {
            for (int a = 0; a < m; a++) {
                st = new StringTokenizer(br.readLine());
                for (int b = 0; b < n; b++) {
                    map[i][a][b] = Integer.parseInt(st.nextToken());
                    if (map[i][a][b] == 1) {
                        q.add(new Tomato(i, a, b, 1));
                        visit[i][a][b] = true;
                        ripeCnt++;
                    } else if (map[i][a][b] == -1) {
                        noTomato++;
                    }
                }
            }
        }

        if (total - ripeCnt == noTomato) {
            System.out.println(0);
            return;
        }

        int tmpCnt = ripeCnt;
        while (!q.isEmpty()) {
            Tomato t = q.poll();

            for (int i = 0; i < 6; i++) {
                int nz = t.z + dir[i][0];
                int ny = t.y + dir[i][1];
                int nx = t.x + dir[i][2];

                if (nz < 0 || nx < 0 || ny < 0 || nz >= h || ny >= m || nx >= n)
                    continue;
                if (!visit[nz][ny][nx] && map[nz][ny][nx] == 0) {
                    q.add(new Tomato(nz, ny, nx, t.cnt + 1));
                    visit[nz][ny][nx] = true;
                    tmpCnt++;
                }
            }

            // need to change this condition
            if (total - tmpCnt == noTomato) {
                ans = Math.min(ans, t.cnt);
                break;
            }
        }

        ans = ans == 987654321 ? -1 : ans;
        System.out.println(ans);
    }

    static class Tomato {
        int z, y, x;
        int cnt;

        Tomato(int z, int y, int x, int cnt) {
            this.z = z;
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    }
}
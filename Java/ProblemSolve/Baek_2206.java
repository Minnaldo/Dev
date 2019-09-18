import java.io.*;
import java.util.*;

public class Baek_2206 {

    static int n, m, ans;
    static int[][] map, dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    static void func(int y, int x, int cnt, boolean chk, boolean[][] visit) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny == n - 1 && nx == m - 1) {
                ans = Math.min(ans, cnt + 1);
                return;
            }

            if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
                if (map[ny][nx] == 1 && !chk) {
                    // 벽을 부수고 넘어감
                    if (!visit[ny][nx]) {
                        visit[ny][nx] = true;
                        func(ny, nx, cnt + 1, true, visit);
                        visit[ny][nx] = false;
                    }
                } else if (!visit[ny][nx] && map[ny][nx] == 0) {
                    visit[ny][nx] = true;
                    func(ny, nx, cnt + 1, chk, visit);
                    visit[ny][nx] = false;
                } else if (map[ny][nx] == 1 && chk) {
                    return;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ans = 987654321;
        map = new int[n][m];

        // init
        for (int i = 0; i < n; i++) {
            char[] tmp = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                map[i][j] = Character.digit(tmp[j], 10);
            }
        }
        boolean[][] visit = new boolean[n][m];
        visit[0][0] = true;
        func(0, 0, 1, false, visit);

        ans = ans == 987654321 ? -1 : ans;
        System.out.println(ans);
    }
}
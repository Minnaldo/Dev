import java.io.*;
import java.util.StringTokenizer;

/**
 * * 등산로 조성
 */

public class SWEA_trail {

    static int n, k, ans;
    static int[][] map, dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    static boolean[][] visit;

    static void solution(int y, int x, int cnt, boolean used) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            if (!visit[ny][nx]) {
                if (map[ny][nx] < map[y][x]) {
                    visit[ny][nx] = true;
                    solution(ny, nx, cnt + 1, used);
                    visit[ny][nx] = false;
                }
                if (map[ny][nx] >= map[y][x] && !used) {
                    for (int a = 0; a <= k; a++)
                        if (map[ny][nx] - a < map[y][x]) {
                            visit[ny][nx] = true;
                            map[ny][nx] -= a;
                            solution(ny, nx, cnt + 1, true);
                            visit[ny][nx] = false;
                            map[ny][nx] += a;
                        }
                }
            }

        }
        ans = Math.max(ans, cnt);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                ans = 0;
                n = Integer.parseInt(st.nextToken());
                k = Integer.parseInt(st.nextToken());
                int heighest = 0;
                map = new int[n][n];
                visit = new boolean[n][n];
                for (int i = 0; i < n; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < n; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                        heighest = Math.max(heighest, map[i][j]);
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (map[i][j] == heighest) {
                            visit[i][j] = true;
                            solution(i, j, 1, false);
                            visit[i][j] = false;
                        }

                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
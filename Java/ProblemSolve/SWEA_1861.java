import java.io.*;
import java.util.StringTokenizer;

// NOTE     가지치기로 속도를 줄일 수 있을 것 같은데
/**
 *  * Record : 592ms, mem : 3300kb
 */

public class SWEA_1861 {

    static int n, ans, startNum, startY, startX;
    static int[][] map, dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    static void dfs(int y, int x, int cnt, int room) {

        boolean flag = false;
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 0 && nx >= 0 && ny < n && nx < n)
                if (map[ny][nx] - 1 == map[y][x]) {
                    flag = true;
                    dfs(ny, nx, cnt + 1, room);
                    break; // 1 더 큰건 하나뿐이다
                }
        }

        if (!flag) {
            if (ans <= cnt) {
                if (ans == cnt) {
                    startNum = startNum < room ? startNum : room;
                } else {
                    startNum = room;
                }
                ans = cnt;
                return;
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ans = 0;
                startNum = 987654321;
                n = Integer.parseInt(br.readLine());

                map = new int[n][n];
                for (int i = 0; i < n; i++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < n; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                    }
                }

                for (int i = 1; i <= n * n; i++) {
                    find(i);
                    if (map[startY][startX] <= (n * n) - ans) {
                        dfs(startY, startX, 1, i);
                    }
                }
                bw.write("#" + tc + " " + startNum + " " + ans + "\n");
            }
            bw.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void find(int a) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == a) {
                    startY = i;
                    startX = j;
                    return;
                }
            }
        }
    }
}
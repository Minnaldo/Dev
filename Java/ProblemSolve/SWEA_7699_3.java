import java.io.*;
import java.util.StringTokenizer;

public class SWEA_7699_3 {

    static int r, c, ans;
    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } }, map;
    static boolean[] visit;

    static void dfs(int y, int x, int cnt) {

        if (ans == 26) {
            return;
        }

        boolean flag = false;
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            int idx = map[ny][nx];
            if (!visit[idx]) {
                visit[idx] = true;
                flag = true;
                dfs(ny, nx, cnt + 1);
                visit[idx] = false;
            }
        }

        if (!flag)
            ans = ans > cnt ? ans : cnt;
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                ans = 0;
                r = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());

                map = new int[r][c];

                for (int i = 0; i < r; i++) {
                    char[] tmp = br.readLine().toCharArray();
                    for (int j = 0; j < c; j++) {
                        map[i][j] = tmp[j] - 'A';
                    }
                }

                visit = new boolean[26];
                visit[map[0][0]] = true;
                dfs(0, 0, 1);

                System.out.println("#" + tc + " " + ans);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
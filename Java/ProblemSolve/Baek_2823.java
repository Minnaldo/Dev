import java.io.*;
import java.util.StringTokenizer;

public class Baek_2823 {

    static int[][] dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    static int sX, sY, ans, r, c;
    static char[][] map;
    static boolean[][] visit;

    static void dfs(int y, int x) {
        if (y == sY && x == sX) {
            ans = 1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
                if (!visit[ny][nx] && map[ny][nx] == '.') {
                    visit[ny][nx] = true;
                    dfs(ny, nx);
                }
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            ans = 0;
            map = new char[r][c];
            visit = new boolean[r][c];
            for (int i = 0; i < r; i++) {
                map[i] = br.readLine().toCharArray();
            }

            loop: for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j] == '.') {
                        sY = i;
                        sX = j;
                        break loop;
                    }
                }
            }

            dfs(sY, sX);

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
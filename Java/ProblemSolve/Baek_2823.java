import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

// 길이 여러개이면 카운트를 해놓는다??

public class Baek_2823 {

    static int[][] delta = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    static int sX, sY, ans, r, c;
    static char[][] map;
    static int[][] visit, visit2;

    static void dfs(int y, int x, int dir) {
        if (y == sY && x == sX) {
            ans = 0;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + delta[i][0];
            int nx = x + delta[i][1];

            if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
                if (visit[ny][nx] != (dir + 2) % 4 && map[ny][nx] == '.' && visit2[ny][nx] > 0) {
                    visit[ny][nx] = i;
                    visit2[ny][nx]--;
                    dfs(ny, nx, i);
                }
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            ans = 1;
            map = new char[r][c];
            visit = new int[r][c];
            visit2 = new int[r][c];

            for (int i = 0; i < r; i++) {
                map[i] = br.readLine().toCharArray();
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j] == '.') {
                        int cnt = 0;
                        for (int k = 0; k < 4; k++) {
                            int ny = i + delta[k][0];
                            int nx = j + delta[k][1];

                            if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
                                if (map[ny][nx] == '.') {
                                    cnt++;
                                }
                            }
                        }
                        visit2[i][j] = cnt;
                    }
                }
            }

            // 시작지점 정하기
            loop: for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j] == '.') {
                        sY = i;
                        sX = j;
                        break loop;
                    }
                }
            }

            for (int[] aa : visit) {
                System.out.println(Arrays.toString(aa));
            }
            dfs(sY, sX, 9);
            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
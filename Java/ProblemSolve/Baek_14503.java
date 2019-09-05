import java.io.*;
import java.util.*;

/**
 *  * 전형적인 시뮬레이션 문제
 *  * 문제에서 요구하는 기능만 구현하면 문제없다
 */

public class Baek_14503 {

    static boolean[][] visit;
    static int[][] map, dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }; // 상 우 하 좌
    static int ans = 0, n, m;
    static Bot bot;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            ans = 1;
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            map = new int[n][m];
            visit = new boolean[n][m];

            st = new StringTokenizer(br.readLine());
            bot = new Bot(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()));

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (map[i][j] == 1)
                        visit[i][j] = true;
                }
            }
            solution();
            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void solution() {
        map[bot.first][bot.second] = 2;
        visit[bot.first][bot.second] = true;
        int nsee = 0;
        int cnt = 0;
        while (true) {
            cnt = 0;
            for (int i = 0; i < 4; i++) {
                nsee = (bot.see - 1) == -1 ? 3 : bot.see - 1;
                int seeY = bot.first + dir[nsee][0];
                int seeX = bot.second + dir[nsee][1];
                if (!visit[seeY][seeX] && map[seeY][seeX] == 0) {
                    bot.see = nsee;
                    bot.first = seeY;
                    bot.second = seeX;
                    visit[seeY][seeX] = true;
                    map[seeY][seeX] = 2;
                    ans++;
                    break;
                } else if (map[seeY][seeX] > 0) {
                    bot.see = nsee;
                    cnt++;
                }
            }
            if (cnt == 4) {
                int ry = bot.first + dir[(bot.see + 2) % 4][0], rx = bot.second + dir[(bot.see + 2) % 4][1];
                if (map[ry][rx] == 1) {
                    break;
                } else {
                    bot.first = ry;
                    bot.second = rx;
                }
            }
        } // end of while
    }

    static class Bot {
        int first, second, see;

        Bot(int first, int second, int see) {
            this.first = first;
            this.second = second;
            this.see = see;
        }
    }
}
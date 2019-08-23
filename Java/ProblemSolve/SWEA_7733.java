import java.io.*;
import java.util.*;

/** 치즈 도둑
 *  * BFS보다 DFS(재귀)가 훨씬 빨랏다
 *  NOTE BFS(534ms / 93,212 kb) /// DFS(302ms / 37,196 kb)
 */

public class SWEA_7733 {
    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    static int[][] map = new int[100][100];
    static int n, ans, max;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                ans = 0;
                n = Integer.parseInt(br.readLine());
                max = 0;

                for (int i = 0; i < n; i++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < n; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                        max = max > map[i][j] ? max : map[i][j];
                    }
                }

                int day = 0;
                while (day <= max) {
                    int mass = 0;
                    boolean[][] visit = new boolean[n][n];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {

                            if (map[i][j] > day && !visit[i][j]) {
                                dfs(i, j, visit, day);
                                // Queue<Pair> q = new LinkedList<>();
                                // q.add(new Pair(i, j));
                                // visit[i][j] = true;

                                // while (!q.isEmpty()) {
                                // int y = q.peek().first;
                                // int x = q.peek().second;

                                // for (int a = 0; a < 4; a++) {
                                // int ny = y + dir[a][0];
                                // int nx = x + dir[a][1];

                                // if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                                // if (!visit[ny][nx] && map[ny][nx] > day) {
                                // q.add(new Pair(ny, nx));
                                // visit[ny][nx] = true;
                                // }
                                // }
                                // }
                                // q.poll();
                                // }
                                mass++;
                            }

                        }
                    }
                    ans = ans > mass ? ans : mass;
                    day++;
                }

                bw.write("#" + tc + " " + ans + "\n");
                bw.flush();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void dfs(int y, int x, boolean[][] visit, int day) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                if (!visit[ny][nx] && map[ny][nx] > day) {
                    visit[ny][nx] = true;
                    dfs(ny, nx, visit, day);
                }
            }
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
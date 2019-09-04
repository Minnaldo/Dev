import java.io.*;
import java.util.*;

public class Baek_2178 {

    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int ans = 0;
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            boolean[][] visit = new boolean[n][m];
            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                char[] tmp = br.readLine().toCharArray();
                for (int j = 0; j < m; j++) {
                    map[i][j] = Character.digit(tmp[j], 10);
                }
            }

            Queue<Pair> q = new LinkedList<>();
            q.add(new Pair(0, 0, 1));
            visit[0][0] = true;
            loop: while (!q.isEmpty()) {
                int cury = q.peek().first;
                int curx = q.peek().second;
                int curlen = q.peek().len;

                for (int i = 0; i < 4; i++) {
                    int ny = cury + dir[i][0];
                    int nx = curx + dir[i][1];

                    if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
                        if (!visit[ny][nx] && map[ny][nx] == 1) {
                            visit[ny][nx] = true;
                            q.add(new Pair(ny, nx, curlen + 1));
                        }
                        if (ny == n - 1 && nx == m - 1) {
                            ans = curlen + 1;
                            break loop;
                        }
                    }
                }
                q.poll();
            }

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second, len;

        Pair(int first, int second, int len) {
            this.first = first;
            this.second = second;
            this.len = len;
        }

    }
}
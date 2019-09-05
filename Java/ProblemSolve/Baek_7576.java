import java.io.*;
import java.util.*;

/**
 * * 완전탐색을 이용하면 시간초과 * 큐를 이용해 풀어야할것 같다 * 1이 보이면 q에 좌표를 집어넣고, -2로 치환 후, 인접 영역으로
 * 확장
 */

public class Baek_7576 {

    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] map = new int[m][n];
            boolean[][] visit = new boolean[m][n];
            Queue<Pair> q = new LinkedList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (map[i][j] == 1) {
                        q.add(new Pair(i, j, 0));
                    }
                }
            }

            int cntMax = 0;
            while (!q.isEmpty()) {
                Pair p = q.poll();
                int day = p.day;
                cntMax = Math.max(cntMax, day);
                if (map[p.first][p.second] == 1) {
                    visit[p.first][p.second] = true;

                    for (int k = 0; k < 4; k++) {
                        int ny = p.first + dir[k][0];
                        int nx = p.second + dir[k][1];
                        if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
                            if (!visit[ny][nx] && map[ny][nx] == 0) {
                                map[ny][nx] = 1;
                                visit[ny][nx] = true;
                                q.add(new Pair(ny, nx, day + 1));
                            }
                        }
                    }
                }
            }

            int day = cntMax;
            loop: for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[i][j] == 0) {
                        day = -1;
                        break loop;
                    }
                }
            }

            System.out.println(day);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second, day;

        Pair(int first, int second, int day) {
            this.first = first;
            this.second = second;
            this.day = day;
        }
    }
}
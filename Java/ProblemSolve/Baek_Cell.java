import java.io.*;
import java.util.*;

public class Baek_Cell {

    static Queue<Cell> cq;
    static int[][] map, dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    static boolean[][] visit;
    static int n, m, k, time, ans, offset = 0;

    // 비활성 상태 체크

    // 세포 확산
    static void spread() {
        ArrayList<Cell> arr = new ArrayList<>(cq);
        cq.clear();
        int[][] tmp = new int[n][m];

        for (int i = 0; i < arr.size(); i++) {
            Cell c = arr.get(i);
            tmp[c.first][c.second] = c.life;
            if (c.activeTime == time)
                for (int j = 0; j < 4; j++) {
                    int ny = c.first + dir[i][0];
                    int nx = c.second + dir[i][1];

                    if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
                        if (map[ny][nx] == 0 && tmp[ny][nx] < c.life && time == c.activeTime) {
                            tmp[ny][nx] = c.life;
                            cq.add(new Cell(ny, nx, c.life, time + c.life, time + (c.life * 2)));
                        }
                        if ((c.startTime + c.life * 2) == time) {
                            visit[c.first][c.second] = true;
                        } else {
                            cq.add(c);
                        }
                    }
                }
        }

        // 임시맵에서 원본맵으로 복사
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                map[i][j] = tmp[i][j];
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                StringTokenizer st = new StringTokenizer(br.readLine());

                n = Integer.parseInt(st.nextToken());
                m = Integer.parseInt(st.nextToken());
                k = Integer.parseInt(st.nextToken());
                time = 0;
                map = new int[n][m];
                visit = new boolean[500][500];
                cq = new LinkedList<>();
                for (int i = offset; i < n + offset; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = offset; j < m + offset; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                        if (map[i][j] > 0) {
                            cq.add(new Cell(i, j, map[i][j], time + map[i][j], time + (2 * map[i][j])));
                        }
                    }
                }
                while (time++ <= 1) {
                    int size = cq.size();
                    for (int i = 0; i < size; i++) {
                        Cell c = cq.poll();
                        cq.add(c);
                    }
                    spread();
                }
                for (int[] a : map) {
                    System.out.println(Arrays.toString(a));
                }

                // while (time++ < k) {

                // }

                System.out.println("#" + tc + " " + ans);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Cell {
        int first, second;
        int life, activeTime, diedTime;

        Cell(int first, int second, int life, int activeTime, int diedTime) {
            this.first = first;
            this.second = second;
            this.life = life;
            this.activeTime = activeTime;
        }
    }
}
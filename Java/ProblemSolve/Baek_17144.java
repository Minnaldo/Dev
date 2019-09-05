import java.io.*;
import java.util.*;

public class Baek_17144 {

    static int r, c, t;
    static int[][] map, copyMap, dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }; // 상, 우, 하, 좌
    static int clearY, clearX;
    static Clear clear1, clear2; // clear1 위쪽, clear2 아래쪽

    static void swap(int by, int bx, int ay, int ax) {
        int tmp = map[by][bx];
        map[by][bx] = map[ay][ax];
        map[ay][ax] = tmp;
    }

    // 공기청정기 위치, 그리고 방향이 들어온다
    static void circular(int y, int x, int direction) {
        boolean[][] visit = new boolean[r][c];
        // visit[y][x] = true;
        int cury = y, curx = x;
        // 위쪽 절반 공기청정기
        while (true) {
            int ny = cury + dir[direction][0];
            int nx = curx + dir[direction][1];
            if (ny == y && nx == x) {
                // 공기청정기까지 돌아왓으므로 종료
                break;
            }

            if (ny >= 0 && nx >= 0 && ny < r && nx < c && ny <= y) {
                swap(cury, curx, ny, nx);
                cury = ny;
                curx = nx;
                visit[ny][nx] = true;
            } else {
                for (int i = 0; i < 4; i++) {
                    int nny = cury + dir[i][0];
                    int nnx = curx + dir[i][1];
                    if (nny >= 0 && nnx >= 0 && nny < r && nnx < c && nny <= y) {
                        if (!visit[nny][nnx] && map[nny][nnx] >= 0) {
                            direction = i;
                            break;
                        }
                    }
                }
            }

        }
        map[y][x + 1] = 0;
    }

    // 아래 절반
    static void circular2(int y, int x, int direction) {
        boolean[][] visit = new boolean[r][c];
        // visit[y][x] = true;
        int cury = y, curx = x;
        // 위쪽 절반 공기청정기
        while (true) {
            int ny = cury + dir[direction][0];
            int nx = curx + dir[direction][1];
            if (ny == y && nx == x) {
                // 공기청정기까지 돌아왓으므로 종료
                break;
            }

            if (ny >= 0 && nx >= 0 && ny < r && nx < c && ny >= y) {
                swap(cury, curx, ny, nx);
                cury = ny;
                curx = nx;
                visit[ny][nx] = true;
            } else {
                for (int i = 0; i < 4; i++) {
                    int nny = cury + dir[i][0];
                    int nnx = curx + dir[i][1];
                    if (nny >= 0 && nnx >= 0 && nny < r && nnx < c && nny >= y) {
                        if (!visit[nny][nnx] && map[nny][nnx] >= 0) {
                            direction = i;
                            break;
                        }
                    }
                }
            }
        }
        map[y][x + 1] = 0;
    }

    static void spread() {

        Queue<Clear> q = new LinkedList<>();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] > 0) {
                    q.add(new Clear(i, j));
                }
            }
        }

        while (!q.isEmpty()) {
            int i = q.peek().first;
            int j = q.peek().second;
            int cnt = 0;
            int dust = map[i][j] / 5;
            for (int k = 0; k < 4; k++) {
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];

                if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                    continue;
                // 공기청정기가 있는 곳
                if (map[ny][nx] != -1) {
                    copyMap[ny][nx] += dust;
                    cnt++;
                }
            }
            copyMap[i][j] += (map[i][j] - (dust * cnt));
            q.poll();
        }

        // map에 cpymap을 복사
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                map[i][j] = copyMap[i][j];
                copyMap[i][j] = 0;
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken()); // t초가 지난후 미세먼지의 양

            map = new int[r][c];
            copyMap = new int[r][c];

            for (int i = 0; i < r; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < c; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (map[i][j] == -1) {
                        copyMap[i][j] = -1;
                        if (clear1 == null) {
                            clear1 = new Clear(i, j);
                        } else {
                            clear2 = new Clear(i, j);
                        }
                    }
                }
            }

            for (int i = 1; i <= t; i++) {
                // 확산
                spread();

                // 위쪽 절반 공기청정기 작동
                circular(clear1.first, clear1.second, 0);
                map[clear1.first][clear1.second] = map[clear2.first][clear2.second] = -1;
                // 아래쪽 절반 공기청정기 작동
                circular2(clear2.first, clear2.second, 2);
                map[clear1.first][clear1.second] = map[clear2.first][clear2.second] = -1;
            }

            int ans = 0;

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j] != -1)
                        ans += map[i][j];
                }
            }
            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Clear {
        int first, second;

        Clear(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
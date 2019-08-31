import java.io.*;
import java.util.StringTokenizer;

/** 백준 파이프 옮기기 ( https://www.acmicpc.net/problem/17070 )
 *
 */

public class Baek_17070 {
    static int n, ans;
    static int[][] dir = { { 1, 1 }, { 0, 1 }, { 1, 0 } }, map;

    static void recur(int y, int x, int curDir) {
        if (y == n && x == n) {
            ans++;
            return;
        }

        if ((y == 1 && x == n) || (y == n && x == 1)) {
            return;
        }

        // 이전 방향에 따라, 갈 수 있는 방향이 정해져있다.
        // 이전 방향 : 가로 ==> 대각선 || 가로 1
        // 이전 방향 : 세로 ==> 대각선 || 세로 2
        // 이전 방향 : 대각선 ==> 대각선 || 세로 || 가로 3

        if (curDir == 0) {
            // 이전 입력 대각선
            // 모든 방향으로 다 이동 가능
            for (int i = 0; i < 3; i++) {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];

                if (i == 0) {
                    if (ny <= n && nx <= n) {
                        if (map[ny][nx] == 0 && map[ny][x] == 0 && map[y][nx] == 0) {
                            recur(ny, nx, 0);
                        }
                    }
                } else {
                    if (ny <= n && nx <= n) {
                        if (map[ny][nx] == 0) {
                            recur(ny, nx, i);
                        }
                    }
                }
            }
        } else if (curDir == 1) {
            // 이전 입력 가로
            for (int i = 0; i < 3; i++) {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];

                if (i == 0) {
                    if (ny <= n && nx <= n) {
                        if (map[ny][nx] == 0 && map[ny][x] == 0 && map[y][nx] == 0) {
                            recur(ny, nx, 0);
                        }
                    }
                } else {
                    if (i != 2)
                        if (ny <= n && nx <= n) {
                            if (map[ny][nx] == 0) {
                                recur(ny, nx, i);
                            }
                        }
                }
            }
        } else {
            // 이전 입력 세로
            for (int i = 0; i < 3; i++) {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];

                if (i == 0) {
                    if (ny <= n && nx <= n) {
                        if (map[ny][nx] == 0 && map[ny][x] == 0 && map[y][nx] == 0) {
                            recur(ny, nx, 0);
                        }
                    }
                } else {
                    if (i != 1)
                        if (ny <= n && nx <= n) {
                            if (map[ny][nx] == 0) {
                                recur(ny, nx, i);
                            }
                        }
                }
            }
        }

    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ans = 0;
                n = Integer.parseInt(br.readLine());
                map = new int[n + 1][n + 1];
                StringTokenizer st;
                for (int i = 1; i <= n; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = 1; j <= n; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                    }
                }

                recur(1, 2, 1);

                System.out.println(ans);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
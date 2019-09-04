import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * * 구슬 탈출 * 상태를 바꾸고 재귀 * 돌아와서 다시 원래대로 복구
 */

public class Baek_13459 {

    static int[][] dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } }, map;
    static int ans, n, m, mul, goalX, goalY;
    static Bead red, blue;

    static void dfs(int cnt) {

        if (ans == 1) {
            return;
        }

        // 기저 영역
        // cnt가 1이 넘어가면 ans를 0으로 바꾸고 종료
        if (cnt > 10) {
            ans = 0;
            return;
        }
        // cnt가 10 이하이면서, 빨간 구슬이 구멍으로 들어가면 cnt로 업데이트 하면서 종료
        // 단, 파란색 구슬이 이번턴에 들어가면 안된다

        // 4개의 방향으로 각 구슬들을 옮기고 넘어간다
        for (int i = 0; i < 4; i++) {
            int pby = blue.first, pbx = blue.second;
            int pry = red.first, prx = red.second;
            boolean pbf = blue.flag, prf = red.flag;

            red = move(red, i, 2);
            blue = move(blue, i, 3);

            map[pby][pbx] = map[pry][prx] = 0;
            map[blue.first][blue.second] = 3;
            map[red.first][red.second] = 2;

            red = move(red, i, 2);
            blue = move(blue, i, 3);

            map[pby][pbx] = map[pry][prx] = 0;
            map[blue.first][blue.second] = 3;
            map[red.first][red.second] = 2;

            if (blue.flag) {
                // 실패조건 : 파란 구슬이 구멍에 빠졌을 때
                ans = 0;
                return;
            } else if (red.flag) {
                // 성공조건 : 파란구슬은 구멍에 안빠졌으나, 빨간구슬은 구멍에 빠졌을 때
                ans = 1;
                return;
            }

            // print_map(map);

            dfs(cnt + 1);

            // 이전으로 상태로 되돌린다
            map[pby][pbx] = 3;
            map[pry][prx] = 2;
            map[blue.first][blue.second] = map[red.first][red.second] = 0;
            red = new Bead(pry, prx, prf);
            blue = new Bead(pby, pbx, pbf);
        }
    }

    private static void print_map(int[][] map2) {
        for (int[] aa : map2) {
            System.out.println(Arrays.toString(aa));
        }
        System.out.println();
    }

    // TODO
    // 기울이는 방향을 받아, 그 방향으로 모든 구슬을 움직이게 한다
    // 다음 좌표가 구슬, 벽 이면 종료
    static Bead move(Bead b, int direction, int color) {
        int cury = b.first, curx = b.second;
        int ny = 0, nx = 0;
        boolean flag = b.flag;

        while (true) {
            ny = cury + dir[direction][0];
            nx = curx + dir[direction][1];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (ny == goalY && nx == goalX) {
                    // 구멍을 만났을 때
                    flag = true;
                }
                // 다음 좌표가 다음 구슬이 이미 있는 좌표일 때
                // 다음 좌표가 벽이여서 더 이상 갈 수 없을 때
                if (map[ny][nx] != 0 || map[ny][nx] == -1) {
                    ny = cury;
                    nx = curx;
                    break;
                }

                cury = ny;
                curx = nx;
            }
        }
        return new Bead(ny, nx, flag);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                n = Integer.parseInt(st.nextToken());
                m = Integer.parseInt(st.nextToken());
                mul = Math.max(n, m);
                map = new int[n][m];
                ans = -1;
                // input data
                for (int i = 0; i < n; i++) {
                    char[] tmp = br.readLine().toCharArray();
                    for (int j = 0; j < m; j++) {
                        switch (tmp[j]) {
                        case '#':
                            map[i][j] = -1;
                            break;
                        case '.':
                            map[i][j] = 0;
                            break;
                        case 'B':
                            blue = new Bead(i, j, false);
                            map[i][j] = 3;
                            break;
                        case 'R':
                            red = new Bead(i, j, false);
                            map[i][j] = 2;
                            break;
                        case 'O':
                            map[i][j] = 1;
                            goalX = j;
                            goalY = i;
                        }
                    }
                }

                // print_map(map);
                for (int i = 2; i < 4; i++) {
                    int pry = red.first, prx = red.second;
                    int pby = blue.first, pbx = blue.second;

                    red = move(red, i, 2);
                    blue = move(blue, i, 3);

                    map[pry][prx] = map[pby][pbx] = 0;
                    map[red.first][red.second] = 2;
                    map[blue.first][blue.second] = 3;
                    System.out.println("red:" + red.toString());
                    System.out.println("blue:" + blue.toString());
                    print_map(map);

                    red = move(red, i, 2);
                    blue = move(blue, i, 3);

                    map[pry][prx] = map[pby][pbx] = 0;
                    map[red.first][red.second] = 2;
                    map[blue.first][blue.second] = 3;

                    print_map(map);
                    System.out.println("red:" + red.toString());
                    System.out.println("blue:" + blue.toString());
                    map[red.first][red.second] = map[blue.first][blue.second] = 0;
                    map[pry][prx] = 2;
                    map[pby][pbx] = 0;

                    red = new Bead(pry, prx, false);
                    blue = new Bead(pby, pbx, false);
                }

                // dfs(0);
                System.out.print("#" + tc + " ");
                System.out.println(ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Bead {
        int first, second;
        boolean flag;

        Bead(int first, int second, boolean flag) {
            this.first = first;
            this.second = second;
            this.flag = flag;
        }

        @Override
        public String toString() {
            return "first = " + this.first + "   second = " + this.second;
        }
    }
}
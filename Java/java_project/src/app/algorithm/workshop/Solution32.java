package app.algorithm.workshop;

/** 발판 게임
 *  주어진 횟수와 방향만큼 이동한 후에, 마지막 칸에 적혀있는 숫자 * 100의 상금을 받을 때, 참가자들의 상금 합계를 구해내는 문제
 */

import java.util.*;

public class Solution32 {

    static int dir[][] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; // 우 하 좌 상

    public static class Person {
        private int y;
        private int x;
        private int dir;
        private int multiply;
        private int jump_cnt;

        Person(int y, int x, int cnt) {
            this.y = y;
            this.x = x;
            this.jump_cnt = cnt;
        }

        public int get_y() {
            return this.y;
        }

        public int get_x() {
            return this.x;
        }

        public int get_dir() {
            return this.dir;
        }

        public int get_multiply() {
            return this.multiply;
        }

        public int get_jump_cnt() {
            return this.jump_cnt;
        }

        public void set_y(int y) {
            this.y = y;
        }

        public void set_x(int x) {
            this.x = x;
        }

        public void set_dir(int dir) {
            this.dir = dir;
        }

        public void set_multily(int multiply) {
            this.multiply = multiply;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int y = sc.nextInt(), x = sc.nextInt(), n = sc.nextInt();
            int[][] map = new int[y + 1][x + 1];
            ArrayList<Person> pArr = new ArrayList<>();
            ans = (-1000) * n;

            // input data of the map
            for (int i = 1; i <= y; i++)
                for (int j = 1; j <= x; j++)
                    map[i][j] = sc.nextInt();

            // info about participate
            for (int i = 0; i < n; i++)
                pArr.add(new Person(sc.nextInt(), sc.nextInt(), sc.nextInt()));

            int hole = sc.nextInt();
            for (int i = 0; i < hole; i++)
                map[sc.nextInt()][sc.nextInt()] = 0; // 함정은 0

            // 탐색 시작
            for (int i = 0; i < n; i++) {
                // 참가자의 점프 횟수를 가져온다
                int jump = pArr.get(i).get_jump_cnt();

                int ny, nx, cx, cy, ndir, nmul;
                while (jump-- > 0) {
                    cx = pArr.get(i).get_x();
                    cy = pArr.get(i).get_y();

                    // 첫 좌표가 함정이 아닐 때
                    if (map[cy][cx] != 0) {
                        ndir = map[cy][cx] / 10; // 다음에 갈 방향
                        nmul = map[cy][cx] % 10; // 다음 점프 거리

                        ny = cy + (dir[ndir][0] * nmul);
                        nx = cx + (dir[ndir][1] * nmul);

                        if (ny >= 1 && nx >= 1 && ny <= y && nx <= x) {
                            if (map[ny][nx] == 0) {
                                // 함정 발판을 밟았을 때
                                pArr.get(i).set_y(0);
                                pArr.get(i).set_x(0);
                                break;
                            } else {
                                pArr.get(i).set_y(ny);
                                pArr.get(i).set_x(nx);
                            }

                        } else {
                            // 경계 밖으로 나갔을 때
                            pArr.get(i).set_y(0);
                            pArr.get(i).set_x(0);
                            break;
                        }
                    }
                } // end of while
            }

            for (int i = 0; i < n; i++)
                ans += (map[pArr.get(i).get_y()][pArr.get(i).get_x()] * 100);

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
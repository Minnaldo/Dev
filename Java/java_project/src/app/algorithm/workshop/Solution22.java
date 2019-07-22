package app.algorithm.workshop;

/**
 *  소금쟁이
 *  소금쟁이가 움직이고 난 후에 살아있는 소금쟁이의 수를 계산하는 문제
 *  소금쟁이 방향과 맵 크기를 보고 미리 맵 밖으로 나가는지 안나가는지 판단할 수 있음 ==> 속도 최적화
 */

import java.util.ArrayList;
import java.util.Scanner;

public class Solution22 {

    static int[][] dir = { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };// 상 하 좌 우

    public static class sogum {
        int y;
        int x;
        int dir;
        int jump_cnt;
        boolean live;

        sogum(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
            this.jump_cnt = 3;
            this.live = true;
        }

        public void setLive(boolean life) {
            this.live = life;
        }

        public void set_x(int x) {
            this.x = x;
        }

        public void set_y(int y) {
            this.y = y;
        }

        public int get_x() {
            return this.x;
        }

        public int get_y() {
            return this.y;
        }

        public int get_dir() {
            return this.dir;
        }

        public boolean isLive() {
            return this.live;
        }

        public int get_jumpCnt() {
            return this.jump_cnt;
        }

        public void decrease_jump_cnt() {
            this.jump_cnt--;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt(); // size of array
            int cnt = sc.nextInt(); // quantity of Sogum
            boolean[][] map = new boolean[n][n];
            ArrayList<sogum> soArr = new ArrayList<>();

            // input data of sogum
            for (int i = 0; i < cnt; i++) {
                int y = sc.nextInt();
                int x = sc.nextInt();
                soArr.add(new sogum(y, x, sc.nextInt()));
                map[y][x] = true;
            }

            // jump start
            for (int i = 0; i < cnt; i++) {
                if (soArr.get(i).isLive()) {
                    for (int j = 3; j > 0; j--) {
                        int sodir = soArr.get(i).dir;
                        int nx = soArr.get(i).get_x() + (dir[sodir][1] * j);
                        int ny = soArr.get(i).get_y() + (dir[sodir][0] * j);
                        map[soArr.get(i).get_y()][soArr.get(i).get_x()] = false;

                        if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
                            // 다음위치가 맵 내부일 때
                            soArr.get(i).set_y(ny);
                            soArr.get(i).set_x(nx);
                            if (map[ny][nx]) {
                                // 가려는 위치에 소금쟁이가 있을 때
                                soArr.get(i).setLive(false); // 소금쟁이 죽음
                            } else {
                                // 가려는 위치에 소금쟁이가 없을 때
                                map[ny][nx] = true;
                            }
                        } else {
                            // 다음 위치가 맵 바깥일 때, 소금쟁이 죽음
                            soArr.get(i).setLive(false);
                        }

                        soArr.get(i).decrease_jump_cnt(); // 점프 횟수 감소
                    }

                    if (soArr.get(i).get_jumpCnt() == 0) {
                        map[soArr.get(i).get_y()][soArr.get(i).get_x()] = true;
                    }
                }
            }

            // 살아있는 소금쟁이 수 계산
            for (int i = 0; i < cnt; i++)
                if (soArr.get(i).isLive())
                    ans++;
            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
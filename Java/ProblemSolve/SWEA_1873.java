import java.io.*;
import java.util.*;

public class SWEA_1873 {
    // 상 하 좌 우 순서
    static int[][] dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    static int h, w;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                h = Integer.parseInt(st.nextToken());
                w = Integer.parseInt(st.nextToken());
                char[][] map = new char[h][w];

                // 맵 입력
                for (int i = 0; i < h; i++) {
                    map[i] = br.readLine().toCharArray();
                }

                // 탱크 객체 생성
                Tank tank = new Tank();

                // 탱크의 초기 위치 및 방향 저장
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        if (map[i][j] == '^') {
                            tank.dir = 0;
                            tank.y = i;
                            tank.x = j;
                            map[i][j] = '.';
                        } else if (map[i][j] == 'v') {
                            tank.dir = 1;
                            tank.y = i;
                            tank.x = j;
                            map[i][j] = '.';
                        } else if (map[i][j] == '<') {
                            tank.dir = 2;
                            tank.y = i;
                            tank.x = j;
                            map[i][j] = '.';
                        } else if (map[i][j] == '>') {
                            tank.dir = 3;
                            tank.y = i;
                            tank.x = j;
                            map[i][j] = '.';
                        }
                    }
                }

                int n = Integer.parseInt(br.readLine()); // 명령어 개수
                char[] oper = br.readLine().toCharArray();

                for (int i = 0; i < n; i++) {
                    // 명령 실행
                    switch (oper[i]) {
                    case 'U':
                        tank = move(map, tank.y, tank.x, 0);
                        break;
                    case 'D':
                        tank = move(map, tank.y, tank.x, 1);
                        break;
                    case 'L':
                        tank = move(map, tank.y, tank.x, 2);
                        break;
                    case 'R':
                        tank = move(map, tank.y, tank.x, 3);
                        break;
                    case 'S':
                        shoot(tank, map, tank.y, tank.x, tank.dir);
                        break;
                    }
                }

                // 마지막 탱크 위치 표시
                switch (tank.dir) {
                case 0:
                    map[tank.y][tank.x] = '^';
                    break;
                case 1:
                    map[tank.y][tank.x] = 'v';
                    break;
                case 2:
                    map[tank.y][tank.x] = '<';
                    break;
                case 3:
                    map[tank.y][tank.x] = '>';
                    break;
                }

                System.out.print("#" + tc + " ");
                // print
                for (char[] aa : map) {
                    for (char val : aa) {
                        System.out.print(val);
                    }
                    System.out.println();
                }

            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void shoot(Tank tank, char[][] map, int y, int x, int ndir) {

        while (true) {
            int ny = y + dir[ndir][0];
            int nx = x + dir[ndir][1];
            if (ny >= 0 && nx >= 0 && ny < h && nx < w) {
                // 강철 벽
                if (map[ny][nx] == '#') {
                    break;
                }
                // 벽돌 벽
                if (map[ny][nx] == '*') {
                    map[ny][nx] = '.';
                    break;
                }

                y = ny;
                x = nx;
            } else {
                break;
            }
        }
    }

    static Tank move(char[][] map, int y, int x, int ndir) {
        int ny = y + dir[ndir][0];
        int nx = x + dir[ndir][1];

        Tank tank = new Tank();
        if (ny >= 0 && nx >= 0 && ny < h && nx < w) {
            if (map[ny][nx] == '.') {
                tank.y = ny;
                tank.x = nx;
            } else {
                tank.y = y;
                tank.x = x;
            }
        } else {
            tank.y = y;
            tank.x = x;
        }
        tank.dir = ndir;
        return tank;
    }

    static class Tank {
        int y, x;
        int dir; // 1 : up, 2 : down, 3 : left, 4 : right

        Tank() {
        }

        Tank(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }
}
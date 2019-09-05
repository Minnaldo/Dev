public class Test {
    static int[][] map, copyMap, dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }; // 상, 우, 하, 좌
    static int r, c;

    static void swap(int by, int bx, int ay, int ax) {
        int tmp = map[by][bx];
        map[by][bx] = map[ay][ax];
        map[ay][ax] = tmp;
    }

    static void circular(int y, int x, int direction) {
        boolean[][] visit = new boolean[r][c];
        // visit[y][x] = true;
        int cury = y, curx = x;
        while (true) {
            int ny = cury + dir[direction][0];
            int nx = curx + dir[direction][1];
            if (ny == y && nx == x) {
                break;
            }

            if (ny >= 0 && nx >= 0 && ny < r && nx < c && ny <= y) {
                System.out.println("cury = " + cury + "   curx = " + curx + "  ny = " + ny + "  nx = " + nx);
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
    }

    public static void main(String[] args) {
        map = new int[7][8];
        r = 7;
        c = 8;
        circular(2, 0, 0);
    }
}
import java.util.Scanner;

class swea_1954 {
    static int n = 0;
    static int dir[][] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; // 0, 1, 2, 3
    static boolean visit[][];
    // 막혔을 때 방향을 바꾼다

    public static void dfs(int[][] map, int x, int y, int dd, int cnt) {
        map[y][x] = cnt;

        int ny = y + dir[dd][0];
        int nx = x + dir[dd][1];

        if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
            if (!visit[ny][nx]) {
                dfs(map, nx, ny, dd, cnt);
            }
        } else {
            dd = (++dd) % 4;
            ny = y + dir[dd][0];
            nx = x + dir[dd][1];
            dfs(map, x, y, dd, cnt);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            n = sc.nextInt();
            int[][] map = new int[n][n];
            visit = new boolean[n][n];
            dfs(map, 0, 0, 0, 1);
            System.out.println("#" + tc + " ");

            for (int[] aa : dir) {
                for (int val : aa) {
                    System.out.print(val);
                }
                System.out.println();
            }

        }
    }
}
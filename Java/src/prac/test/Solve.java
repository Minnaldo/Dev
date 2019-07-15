package src.prac.test;

import java.util.Scanner;

class Solve {
    static int dir[][] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    static boolean visit[][];
    static int num = 0;
    static int ans[][];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            num = sc.nextInt();
            visit = new boolean[num][num];
            ans = new int[num][num];
            dfs(0, 0, 1);

            for (int i = 0; i < num; i++) {
                for (int j = 0; j < num - 1; j++) {
                    System.out.print(ans[i][j] + " ");
                }

                System.out.println(ans[i][num - 1]);
            }
        }

        sc.close();
    }

    static public void dfs(int y, int x, int cnt) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            ans[y][x] = cnt;

            if (ny >= 0 && nx >= 0 && ny < num && nx < num) {
                if (!visit[ny][nx]) {
                    dfs(ny, nx, cnt + 1);
                }
            }
        }
    }
}
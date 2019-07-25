import java.util.Scanner;

public class SWEA_1954 {

    static int dir[][] = { {}, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int[][] ans = new int[n][n];
            boolean[][] visit = new boolean[n][n];

            int cnt = 1;
            int cy = 0;
            int cx = 0;
            int direction = 1;
            ans[cy][cx] = cnt++;
            visit[cy][cx] = true;
            int baseVar = n * n;
            while (cnt <= baseVar) {
                int ny = cy + dir[direction][0];
                int nx = cx + dir[direction][1];

                if ((ny >= n || nx >= n || ny < 0 || nx < 0) || visit[ny][nx]) {
                    direction = direction % 4 + 1;
                } else if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                    if (!visit[ny][nx]) {
                        ans[ny][nx] = cnt;
                        visit[ny][nx] = true;
                        cy = ny;
                        cx = nx;
                        cnt++;
                    }
                }
            }
            System.out.println("#" + tc);
            for (int[] aa : ans) {
                for (int val : aa) {
                    System.out.print(val + " ");
                }
                System.out.println();
            }
        }

        sc.close();
    }
}
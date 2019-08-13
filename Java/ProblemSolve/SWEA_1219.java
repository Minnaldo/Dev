import java.util.Scanner;

public class SWEA_1219 {

    static int[][] map;
    static boolean[] visit;
    static int n = 100, ans = 0;

    public static void dfs(int v) {
        if (v == 99) {
            ans = 1;
            return;
        }

        visit[v] = true;
        for (int i = 0; i < n; i++) {
            if (map[v][i] == 1 && !visit[i]) {
                dfs(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int tc = 1; tc <= 10; tc++) {
            int t = sc.nextInt();
            map = new int[n][n];
            visit = new boolean[n];
            ans = 0;
            int k = sc.nextInt();
            // 기본 false로 초기화

            for (int i = 0; i < k; i++) {
                int y = sc.nextInt();
                int x = sc.nextInt();
                map[y][x] = 1;
            }

            dfs(0);

            System.out.println("#" + tc + " " + ans);
        }

    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
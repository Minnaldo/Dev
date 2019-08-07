import java.io.*;
import java.util.*;

public class SWEA_2806 {
    static int[][] dir = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

    static int n, ans;

    public static void func(int[][] map, boolean[][] visit, int y, int x) {
        if (y + 1 == n) {
            ans++;
            return;
        }
        // 방문 체크 배열에 놓지 못하는곳 체크하기
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < n; j++) {
                int ny = y + dir[i][0] * j;
                int nx = x + dir[i][1] * j;
                if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                    visit[ny][nx] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visit[y + 1][i])
                func(map, visit, y + 1, i);
        }

    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("file_name")) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                n = sc.nextInt();

                int[][] map = new int[n][n];
                boolean[][] visit = new boolean[10][10]; // n의 크기가 최대 10

                // 경우의 수를 구해야 한다.
                // 모든 칸을 돌며 첫 퀸을 하나씩 둔다.
                // 이어서 다음칸에 퀸을 놓을수 있는 경우의 수를 센다.

                for (int i = 0; i < n; i++) {
                    if (!visit[0][i])
                        func(map, visit, 0, i);
                }

                System.out.println("#" + tc + " " + ans);
            }
            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
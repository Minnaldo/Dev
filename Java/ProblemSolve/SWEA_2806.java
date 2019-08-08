import java.io.*;
import java.util.*;

public class SWEA_2806 {
    static int[][] dir = { { 1, -1 }, { 1, 0 }, { 1, 1 } };
    static int n, ans;

    public static void func(boolean[][] visit, int y, int x) {
        if (y == n - 1) {
            ans++;
            System.out.println("find answer");
            return;
        }

        // 배열 복사
        boolean[][] tmp = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(visit[i], 0, tmp[i], 0, n);
        }

        // 방문 체크 배열에 퀸을 놓지 못하는곳 체크하기
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n + 4; j++) {
                int ny = y + dir[i][0] * j;
                int nx = x + dir[i][1] * j;
                if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                    visit[ny][nx] = true;
                }
            }
        }
        print(visit, false);

        for (int i = 0; i < n; i++) {
            if (!visit[y + 1][i]) {
                func(visit, y + 1, i);
                // 나왔을 때 방문 배열을 이전상태로 돌려준다.
                visit = tmp;
                print(visit, true);
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            ans = 0;
            n = sc.nextInt();

            boolean[][] visit = new boolean[10][10]; // n의 크기가 최대 10
            boolean[][] zeroVisit = new boolean[10][10];

            for (int i = 0; i < n; i++) {
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < n + 4; b++) {
                        int ny = 0 + dir[a][0] * b;
                        int nx = i + dir[a][1] * b;
                        if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                            visit[ny][nx] = true;
                        }
                    }
                }
                func(visit, 0, i);

                for (int q = 0; q < 10; q++) {
                    System.arraycopy(zeroVisit[q], 0, visit[q], 0, 10);
                }
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }

    public static void print(boolean[][] visit, boolean flag) {
        if (flag)
            System.out.println("==================AFTER===================");
        else
            System.out.println("==================BEFORE===================");

        for (int q = 0; q < n; q++) {
            for (int j = 0; j < n; j++) {
                if (visit[q][j]) {
                    System.out.print(1 + " ");
                } else {
                    System.out.print(0 + " ");
                }
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("==========================================");
        System.out.println();
    }
}
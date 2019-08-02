import java.util.*;
import java.io.*;

public class SWEA_2805 {

    public static class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in;
            int t = sc.nextInt();

            // 전처리
            int[] arr = new int[50];
            arr[1] = 1;
            for (int i = 3; i < 50; i += 2) {
                int tmp = i / 2;
                arr[i] = arr[i - 2] + (4 * tmp);
            }

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;

                int n = sc.nextInt();

                int[][] map = new int[n][n];
                boolean[][] visit = new boolean[n][n];
                for (int i = 0; i < n; i++) {
                    String str = sc.next();
                    for (int j = n - 1; j >= 0; j--) {
                        map[i][j] = Character.digit(str.charAt(j), 10);
                        visit[i][j] = false;
                    }
                }

                if (n == 1) {
                    ans = map[0][0];
                } else {
                    int c = n / 2;
                    int limit = arr[n - 2];

                    // n이 1이상 일때
                    int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
                    Queue<pair> q = new LinkedList<pair>();
                    ans += map[c][c];
                    visit[c][c] = true;
                    q.add(new pair(c, c));
                    int x = 0, y = 0;

                    for (int a = 0; a < limit; a++) {

                        x = q.peek().second;
                        y = q.peek().first;

                        for (int i = 0; i < 4; i++) {
                            int ny = y + dir[i][0];
                            int nx = x + dir[i][1];

                            if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                                if (!visit[ny][nx]) {
                                    ans += map[ny][nx];
                                    map[ny][nx] = 0;
                                    visit[ny][nx] = true;
                                    q.add(new pair(ny, nx));
                                }
                            }
                        }
                        q.poll();
                    }
                }
                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
    }
}
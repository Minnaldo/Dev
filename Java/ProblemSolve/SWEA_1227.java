import java.util.*;

public class SWEA_1227 {

    static class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = 100;

        for (int tc = 1; tc <= 10; tc++) {
            int t = sc.nextInt();
            int ans = 0;
            int[][] maze = new int[n][n];
            boolean[][] visit = new boolean[n][n];
            int finY = 0, finX = 0;
            for (int i = 0; i < n; i++) {
                String str = sc.next();
                for (int j = 0; j < str.length(); j++) {
                    maze[i][j] = Character.digit(str.charAt(j), 10);
                    if (maze[i][j] == 3) {
                        finY = i;
                        finX = j;
                    }
                }
            }

            int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

            Queue<pair> q = new LinkedList<>();
            q.add(new pair(finY, finX));
            int cury, curx;

            while (!q.isEmpty()) {
                cury = q.peek().first;
                curx = q.peek().second;

                for (int i = 0; i < 4; i++) {
                    int ny = cury + dir[i][0];
                    int nx = curx + dir[i][1];

                    if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                        if (!visit[ny][nx] && maze[ny][nx] != 1) {
                            if (maze[ny][nx] == 2) {
                                ans = 1;
                                break;
                            }
                            q.add(new pair(ny, nx));
                            visit[ny][nx] = true;
                        }
                    }
                }
                q.poll();
            }

            System.out.println("#" + tc + " " + ans);
        }
    }
}
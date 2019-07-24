import java.io.FileInputStream;
import java.util.*;

public class SWEA_1227 {

    class pair {

        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();
            int n = 100;
            int[][] maze = new int[n][n];
            boolean[][] visit = new visit[n][n];

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        maze[i][j] = sc.nextInt();
                    }
                }

                int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

                Queue<pair> q = new Queue<>();
                q.add(new pair(1, 1));
                int cury, curx;

                while (!q.isEmpty()) {
                    cury = q.peek().first;
                    curx = q.peek().second;

                    for (int i = 0; i < 4; i++) {
                        int ny = cury + dir[i][0];
                        int nx = curx + dir[i][1];

                        if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                            if (!visit[ny][nx] && maze[ny][nx] != 1) {
                                if (maze[ny][nx] == 3) {
                                    ans = 1;
                                    break;
                                }
                                q.add(new pair(ny, nx));
                                visit[ny][nx] = true;
                            }
                        }
                    }
                    q.remove();
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            fis.close();
        }
    }

}
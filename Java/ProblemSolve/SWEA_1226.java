import java.util.*;

public class SWEA_1226 {
    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    static int[][] map;
    static boolean[][] visit;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int tc = 1; tc <= 10; tc++) {
            int ans = 0;
            int aa = sc.nextInt();
            int n = 16;
            map = new int[16][16];
            visit = new boolean[16][16];
            Queue<Pair> q = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                String tmp = sc.next();
                for (int j = 0; j < tmp.length(); j++) {
                    map[i][j] = Character.digit(tmp.charAt(j), 10);
                    if (map[i][j] == 3) {
                        q.add(new Pair(i, j));
                    }
                }
            }

            while (!q.isEmpty()) {
                int y = q.peek().first;
                int x = q.peek().second;

                for (int i = 0; i < 4; i++) {
                    int ny = y + dir[i][0];
                    int nx = x + dir[i][1];

                    if (ny >= 0 && nx >= 0 && ny < n && nx <= n) {
                        if (!visit[ny][nx] && map[ny][nx] != 1) {
                            if (map[ny][nx] == 2) {
                                ans = 1;
                                break;
                            }
                            visit[ny][nx] = true;
                            q.add(new Pair(ny, nx));
                        }
                    }
                }

                q.poll();
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
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
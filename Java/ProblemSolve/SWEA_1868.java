import java.io.*;
import java.util.*;

public class SWEA_1868 {

    static int[][] dir = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            // new FileInputStream("input.txt")
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = Integer.parseInt(br.readLine());

                // init
                char[][] map = new char[n][n];
                int[][] cntMap = new int[n][n];
                boolean[][] visit = new boolean[n][n];
                for (int i = 0; i < n; i++) {
                    map[i] = br.readLine().toCharArray();
                }

                ArrayList<Pair> arr = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cntMap[i][j] = -1;
                        if (map[i][j] == '.') {
                            int cnt = 0;
                            for (int a = 0; a < 8; a++) {
                                int ny = i + dir[a][0];
                                int nx = j + dir[a][1];
                                if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                                    if (map[ny][nx] == '*')
                                        cnt++;
                                }
                            }
                            if (cnt == 0) {
                                arr.add(new Pair(i, j));
                            }
                        }
                    }
                }

                for (int i = 0; i < arr.size(); i++) {
                    int y = arr.get(i).first;
                    int x = arr.get(i).second;

                    if (cntMap[y][x] == -1) {
                        Queue<Pair> q = new LinkedList<>();
                        q.add(new Pair(y, x));

                        while (!q.isEmpty()) {

                            int iy = q.peek().first;
                            int ix = q.peek().second;
                            if (map[iy][ix] == '.') {
                                int tmp = 0;
                                visit[iy][ix] = true;
                                for (int a = 0; a < 8; a++) {
                                    int ny = iy + dir[a][0];
                                    int nx = ix + dir[a][1];

                                    if (ny >= 0 && nx >= 0 && ny < n && nx < n && !visit[ny][nx]) {
                                        if (map[ny][nx] == '*')
                                            tmp++;
                                        else if (tmp == 0)
                                            q.add(new Pair(ny, nx));
                                    }
                                }
                                cntMap[iy][ix] = tmp;
                                q.poll();
                            }
                        }
                        ans++;
                    }
                }

                // for (int[] aa : cntMap) {
                //     for (int val : aa) {
                //         System.out.print(val + " ");
                //     }
                //     System.out.println();
                // }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (map[i][j] == '.' && cntMap[i][j] == -1)
                            ans++;
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
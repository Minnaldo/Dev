import java.io.*;
import java.util.*;

public class Baek_2468 {
    static StringTokenizer st;
    static int n;
    static int[][] map = new int[n][n], dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    static ArrayList<Integer> arr;
    static HashSet<Integer> set;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine());
            map = new int[n][n];
            set = new HashSet<>();

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    set.add(map[i][j]);
                }
            }
            arr = new ArrayList<>(set);
            arr.add(0);
            Collections.sort(arr);

            int ans = 0;
            for (int day : arr) {
                int cnt = 0;
                boolean[][] visit = new boolean[n][n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (!visit[i][j] && map[i][j] > day) {
                            dfs(visit, i, j, day);
                            cnt++;
                        }
                    }
                }
                ans = ans > cnt ? ans : cnt;
            }

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void dfs(boolean[][] visit, int y, int x, int day) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
                if (!visit[ny][nx] && map[ny][nx] > day) {
                    visit[ny][nx] = true;
                    dfs(visit, ny, nx, day);
                }
            }

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
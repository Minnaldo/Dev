import java.io.*;
import java.util.StringTokenizer;

/**
 * 색종이의 둘레를 구한다
 */

public class Baek_2567 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            boolean[][] map = new boolean[102][102];
            int[][] map2 = new int[102][102];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                // 색종이를 전부 칠한다
                for (int j = a; j < a + 10; j++) {
                    for (int k = b; k < b + 10; k++) {
                        map[j][k] = true;
                    }
                }
            }

            int ans = 0;
            int dir[][] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
            for (int i = 1; i <= 100; i++) {
                for (int j = 1; j < 100; j++) {
                    if (map[i][j]) {
                        for (int k = 0; k < 4; k++) {
                            int ny = i + dir[k][0];
                            int nx = j + dir[k][1];

                            if (ny >= 0 && nx >= 0 && ny <= 101 && nx <= 101) {
                                if (!map[ny][nx]) {
                                    map2[ny][nx]++;
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < map2.length; i++) {
                for (int j = 0; j < map2[0].length; j++) {
                    if (map2[i][j] > 0)
                        ans += map2[i][j];
                }
            }

            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
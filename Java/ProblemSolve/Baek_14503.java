import java.io.*;
import java.util.*;

public class Baek_14503 {

    static int[][] dir = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
    static int[][] dir2 = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] map = new int[n + 2][m + 2];

            int ans = 1;

            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()) + 1;
            int c = Integer.parseInt(st.nextToken()) + 1;
            int see = Integer.parseInt(st.nextToken());

            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 1; j <= m; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < n + 2; i++) {
                map[i][0] = map[i][m + 1] = 1;
            }
            for (int i = 0; i < m + 2; i++) {
                map[0][i] = map[n + 1][i] = 1;
            }

            // 현재 로봇청소기가 있는 곳을 청소한 곳으로 만든다.
            map[r][c] = -1;
            while (true) {
                int cnt = 0;
                int cnt2 = 0;
                for (int i = 0; i < 4; i++, cnt2++) {
                    int ny = r + dir[(i + see) % 3][0];
                    int nx = c + dir[(i + see) % 3][0];

                    if (cnt2 == 3) {
                        break;
                    }

                    if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
                        if (map[ny][nx] == 0) {
                            // 청소하지 않은 구역일 때
                            see = (i + see) % 3;
                            r = ny;
                            c = nx;
                            map[r][c] = -1;
                            ans++;
                            break;
                        } else {
                            see = (i + see) % 3;
                            cnt++;
                        }
                    }
                }

                if (cnt == 3) {
                    // 후진 좌표를 구한다
                    int ry = r + dir2[(see + 2) % 4][0];
                    int rx = c + dir2[(see + 2) % 4][0];

                    if (map[ry][rx] == 1) {
                        break;
                    } else {
                        r = ry;
                        c = rx;
                    }
                }
            }

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
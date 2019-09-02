import java.io.*;
import java.util.*;

<<<<<<< Updated upstream
//  TODO

/**
 * * 완전탐색을 이용하면 시간초과 * 큐를 이용해 풀어야할것 같다 * 1이 보이면 q에 좌표를 집어넣고, -2로 치환 후, 인접 영역으로
 * 확장
=======
/**
 *  * 완전탐색을 이용하면 시간초과
 *  * 큐를 이용해 풀어야할것 같다
 *  * 1이 보이면 q에 좌표를 집어넣고, -2로 치환 후, 인접 영역으로 확장
>>>>>>> Stashed changes
 */

public class Baek_7576 {

<<<<<<< Updated upstream
    public static void main(String[] args) {
=======
    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] map = new int[m][n];
            int[][] tmp = new int[m][n];

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (map[i][j] == 1) {
                        tmp[i][j] = 1;
                    }
                }
            }

            int day = 0;
            int idx = 1;
            while (true) {
                boolean flag = false;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (map[i][j] == 1 && tmp[i][j] == idx) {
                            for (int k = 0; k < 4; k++) {
                                int ny = i + dir[k][0];
                                int nx = j + dir[k][1];
                                if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
                                    if (map[ny][nx] == 0 && tmp[ny][nx] < idx) {
                                        map[ny][nx] = 1;
                                        tmp[ny][nx] = idx + 1;
                                        flag = true;
                                    }
                                }
                            }
                        }
                    }
                }

                if (!flag)
                    break;
                day++;
                idx++;
            }

            loop: for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[i][j] == 0) {
                        day = -1;
                        break loop;
                    }
                }
            }

            System.out.println(day);
        } catch (Exception e) {
            e.printStackTrace();
        }
>>>>>>> Stashed changes
    }
}
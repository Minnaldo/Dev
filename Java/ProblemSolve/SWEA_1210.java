
/**
 *  * 적용 아이디어 : 골인지점에서 역으로 찾아나간다
 *  * DFS를 적용
 */

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA_1210 {
    static int[][] dir = { { 0, -1 }, { 0, 1 }, { -1, 0 } }; // 좌, 우, 상
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int tc = 1; tc <= 10; tc++) {
            int ans = 0;

            int ttmpc = sc.nextInt();
            int[][] map = new int[100][100];
            boolean[][] visit = new boolean[100][100];
            int goalX = 0, goalY = 0;
            // init, get input
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    map[i][j] = sc.nextInt();
                    // 골인지점을 찾는다
                    if (map[i][j] == 2) {
                        goalY = i;
                        goalX = j;
                    }
                }
            }
            int cx = goalX;
            int cy = goalY;
            while (cy > 0) {

                for (int i = 0; i < 3; i++) {
                    int ny = cy + dir[i][0];
                    int nx = cx + dir[i][1];

                    if (ny >= 0 && nx >= 0 && ny < 100 && nx < 100) {
                        if (!visit[ny][nx] && map[ny][nx] > 0) {
                            visit[ny][nx] = true;
                            cy = ny;
                            cx = nx;
                        }
                    }
                }
            }
            ans = cx;
            System.out.println("#" + tc + " " + ans);
        }
    }
}
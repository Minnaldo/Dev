import java.io.*;
import java.util.*;

public class Baek_17069_2 {
    static int[][] dir = { { 1, 1 }, { 1, 0 }, { 0, 1 } }, map;
    static int[][][] dp;

    static int func(int pnum, int y, int x) {
        // 가지치기 : 메모이제이션 dp
        if (dp[pnum][y][x] > 0) {
            return dp[pnum][y][x];
        }

        int tmp = 0;
        // 갈수 있는 모든 방향에 대해서 판단한다
        if (pnum == 0) {
            // 대각선으로 들어옴 : 모든방향 가능
            tmp += func(pnum, y+dir[pnum][0], x+dir[pnum][1]);
            tmp += func(1, y+dir[1][0], x+dir[1][1]);
            tmp += func(2, y+dir[2][0], x+dir[2][1]);
        } else if (pnum == 1) {
            // 세로로 들어옴 : 대각선 또는 세로
            tmp += func(0, y+dir[0][0], x+dir[0][1]);
            tmp += func(pnum, y+dir[pnum][0], x+dir[pnum][1]);
        } else {
            // 가로로 들어옴 : 대각선 또는 가로
            tmp += func(0, y+dir[0][0], x+dir[0][1]);
            tmp += func(pnum, y+dir[pnum][0], x+dir[pnum][1]);
        }
        dp[pnum][y][x] = tmp;
        return dp[pnum][y][x];
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        dp = new int[3][n][n];
        map = new int[n][n];
        StringTokenizer st = null;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = func(2, 0, 0);
        System.out.println(ans);
    }
}
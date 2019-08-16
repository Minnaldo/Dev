import java.util.*;
import java.io.*;

public class SWEA_1249 {

    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    static int n, ans;

    static void func(int[][] map, int y, int x, int sum) {

        if (y == 0 && x == 0) {
            ans = sum;
            return;
        }

        int tmp = 0, tmpy = 0, tmpx = 0;
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            // ny, nx의 좌표값을 보정
            if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                if (map[ny][nx] <= tmp) {
                    tmpy = ny;
                    tmpx = nx;
                    tmp = map[ny][nx];
                }
            }
        }

        func(map, tmpy, tmpx, sum + tmp);
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();

            for (int tc = 1; tc <= t; tc++) {
                ans = 987654321;
                n = sc.nextInt();
                int[][] map = new int[n][n];

                for (int i = 0; i < n; i++) {
                    String str = sc.next();

                    for (int j = 0; j < str.length(); j += (str.length() / n)) {
                        // System.out.println(str.substring(j, j + str.length() / n));
                        map[i][j] = Integer.parseInt(str.substring(j, j + (str.length() / n)));
                    }
                }

                func(map, 99, 99, 0);

                System.out.println("#" + tc + " " + ans);
            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.util.ArrayList;
import java.util.Scanner;

/**
 * 금요 프로젝트 : 2차원 배열 활용 - 1
 *
 */

public class Solution13 {

    // 주변 검색하기 위한 배열
    static int[][] dir = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 1, 0 }, { 1, 1 }, { 1, -1 }, { 0, 1 } };

    public static class pair {
        int first;
        int second;

        pair(int y, int x) {
            this.first = y;
            this.second = x;
        }

        public int first() {
            return this.first;
        }

        public int second() {
            return this.second;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt();

            int[][] map = new int[n][n];
            int[][] retMap = new int[n][n];
            ArrayList<pair> arr = new ArrayList<>();

            // data input
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    String tmp = sc.next();
                    if (tmp.equals("G")) {
                        map[i][j] = 0;
                    } else {
                        map[i][j] = 1;
                    }
                }
            }

            // 주변 검색
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[i][j] == 1) {
                        boolean flag = false;
                        for (int k = 0; k < 8; k++) {
                            int ny = i + dir[k][0];
                            int nx = j + dir[k][1];

                            if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                                if (map[ny][nx] == 0) {
                                    flag = true;
                                    retMap[i][j] = 2;
                                }
                            }
                        }

                        if (!flag) {
                            arr.add(new pair(i, j));
                        }

                    }
                }
            }

            // B의 갯수 찾기
            for (int i = 0; i < arr.size(); i++) {
                int y = arr.get(i).first;
                int x = arr.get(i).second;
                int tall = 0;
                for (int j = 0; j < n; j++) {
                    tall += map[j][x] + map[y][j];
                }
                tall -= 1;
                retMap[y][x] = tall;
            }

            for (int[] aa : retMap) {
                for (int val : aa) {
                    ans = ans > val ? ans : val;
                }
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
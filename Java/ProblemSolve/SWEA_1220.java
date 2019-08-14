import java.util.Scanner;

/**
 *  * 한쪽 방향에서만 넘어가면서 계산한다.
 *  * 교차될때만 1씩 증가하므로, 파란색 기준이면
 *  * 파란색 자석이 나오면 1, 빨간색이나오면 결과에 더하고 0으로 초기화를 반복하면 된다
 */

public class SWEA_1220 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int tc = 1; tc <= 10; tc++) {
            int n = sc.nextInt();
            int[][] map = new int[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = sc.nextInt();
                }
            }
            int ans = 0;
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (map[i][j] == 1) {
                        cnt = 1;
                    } else if (map[i][j] == 2) {
                        ans += cnt;
                        cnt = 0;
                    }
                }
            }
            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
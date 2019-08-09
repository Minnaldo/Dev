import java.util.Scanner;

public class SWEA_1961 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;

            int n = sc.nextInt();

            int[][] map = new int[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = sc.nextInt();
                }
            } // end of input

            StringBuilder sb = new StringBuilder();
            int idx = 0;
            while (idx < n) {
                // y-- 0~n;
                for (int i = n - 1; i >= 0; i--) {
                    sb.append(map[i][idx]);
                }
                sb.append(" ");
                // x-- n ~0
                for (int i = n - 1; i >= 0; i--) {
                    sb.append(map[n - 1 - idx][i]);
                }
                sb.append(" ");
                // y++ n ~0
                for (int i = 0; i < n; i++) {
                    sb.append(map[i][n - 1 - idx]);
                }
                sb.append("\n");
                idx++;
            }
            System.out.print("#" + tc + "\n" + sb.toString());
        }
        sc.close();
    }
}
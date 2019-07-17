import java.util.Scanner;

class swea_2001 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] map = new int[n][n];
            // int[][] sum = new int[n + 1][n + 1];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + sum[i - 1][j - 1] + sc.nextInt();
                    map[i][j] = sc.nextInt();
                }
            }

            int limit = n - m + 1;

            for (int a = 0; a < limit; a++) {
                for (int b = 0; b < limit; b++) {
                    int sum = 0;
                    for (int i = a; i < a+m; i++) {
                        for (int j = b; j < b+m; j++) {
                            sum += map[i][j];
                        }
                    }

                    ans = ans > sum ? ans : sum;
                }
            }

            // ans = sum[m-1][m-1];
            // for (int i = m - 1; i < n; i++) {
            // for (int j = m - 1; j < n; j++) {
            // ans = ans > (sum[i][j])
            // }
            // }

            System.out.println("#" + tc + " " + ans);
        }
    }
}
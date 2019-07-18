
import java.util.Scanner;

class swea_2001_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt();
            int m = sc.nextInt();
            // int[][] map = new int[n][n];
            int[][] sum = new int[n + 1][n + 1];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + sum[i - 1][j - 1] + sc.nextInt();
                }
            }

            for(int[] a : sum)
            {
                for(int aa : a)
                    System.out.print(aa);
                System.out.println();
            }

            // int limit = n - m + 1;

            // for(int i = m; i<n; i++)
            // {
            //     for(int j = m; j<n; j++)
            //     {

            //     }
            // }

            System.out.println("#" + tc + " " + ans);
        }
    }
}
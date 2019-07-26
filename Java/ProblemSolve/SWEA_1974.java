import java.util.*;

public class SWEA_1974 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 1;
            int n = 9;
            int[][] map = new int[n][n];
            int[] col = new int[n];
            int[] row = new int[n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = sc.nextInt();
                    row[i] += map[i][j];
                    col[j] += map[i][j];
                }
            }

            for (int i = 0; i < n; i += 3) {
                for (int j = 0; j < n; j += 3) {
                    int tmpSum = 0;
                    for (int a = i; a < i + 3; a++) {
                        for (int b = j; b < j + 3; b++) {
                            tmpSum += map[a][b];
                        }
                    }

                    if (tmpSum != 45) {
                        ans = 0;
                    }

                }
            }

            if (ans == 1) {
                for (int i = 0; i < n; i++) {
                    if (col[i] != 45 || row[i] != 45) {
                        ans = 0;
                        break;
                    }
                }
            }

            System.out.println("#" + tc + " " + ans);
        }
    }
}
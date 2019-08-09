import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA_1979 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;

                int n = sc.nextInt();
                int k = sc.nextInt();

                int[][] map = new int[n + 2][n + 2];

                for (int i = 0; i < n + 2; i++) {
                    map[i][0] = map[0][i] = map[i][n + 1] = map[n + 1][i] = 1;
                }

                for (int i = 1; i < n; i++) {
                    for (int j = 1; j < n; j++) {
                        map[i][j] = sc.nextInt();
                    }
                }
                // end to make the map




                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
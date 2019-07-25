import java.util.*;
import java.io.*;

public class SWEA_1979 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = sc.nextInt();
                int k = sc.nextInt();

                int[] row = new int[n];
                int[] col = new int[n];
                int[][] map = new int[n][n];

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        map[i][j] = sc.nextInt();
                    }
                }
                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
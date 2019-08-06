import java.io.*;
import java.util.*;

public class SWEA_2806 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("file_name")) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = sc.nextInt();

                int[][] map = new int[n][n];
                boolean[][] visit = new boolean[n][n];

                // 경우의 수를 구해야 한다.
                // 모든 칸을 돌며 첫 퀸을 하나씩 둔다.
                //  이어서 다음칸에 퀸을 놓을수 있는 경우의 수를 센다.



                System.out.println("#" + tc + " " + ans);
            }
            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
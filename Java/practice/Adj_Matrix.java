import java.io.*;
import java.util.*;

public class Adj_Matrix {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] map = new int[n][n];

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                map[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = Integer
                        .parseInt(st.nextToken());
            }

            for (int[] aa : map) {
                System.out.println(Arrays.toString(aa));
            }
            System.out.println();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
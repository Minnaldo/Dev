import java.io.*;
import java.util.*;

public class Adj_Matrix_2 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_2.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] map = new int[n+1][n+1];
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                map[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = 1;
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
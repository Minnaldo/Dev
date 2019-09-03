import java.io.*;
import java.util.StringTokenizer;

public class Baek_1473 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                char[] tmp = br.readLine().toCharArray();
                for (int j = 0; j < m; j++) {
                    map[i][j] = tmp[j] - 'A';
                }
            }



        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
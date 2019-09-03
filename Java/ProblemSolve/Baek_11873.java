import java.io.*;
import java.util.StringTokenizer;

public class Baek_11873 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            while (true) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());
                if (n == 0 || m == 0)
                    break;

                int[][] map = new int[n][m];

                for (int i = 0; i < n; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < m; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                    }
                }

                int yoffset = 0, xoffset = 0;

                int cnt = 0;
                for (int i = 0 + yoffset; i < n - yoffset + i; i++) {
                    for (int j = 0; j < m; j++) {
                        if (map[i][j] == 1)
                            cnt++;
                        else{
                            cnt=0;
                            yoffset++;
                        }
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0 + xoffset; j < m - xoffset + j; j++) {

                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
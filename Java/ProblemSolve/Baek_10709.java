import java.io.*;
import java.util.StringTokenizer;

/**
 *  기상캐스터
 */

public class Baek_10709 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int h = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            char[][] map = new char[h][w];
            int[][] ans = new int[h][w];

            for (int i = 0; i < h; i++) {
                char tmp[] = br.readLine().toCharArray();
                for (int j = 0; j < w; j++) {
                    map[i][j] = tmp[j];
                    if (tmp[j] == 'c')
                        ans[i][j] = 0;
                    else
                        ans[i][j] = -1;
                }
            }

            for (int i = 0; i < h; i++) {
                int cnt = 0;
                boolean flag = false;
                for (int j = 0; j < w; j++) {
                    if (map[i][j] == 'c') {
                        flag = true;
                        cnt = 0;
                    } else {
                        if (flag)
                            ans[i][j] = ++cnt;
                    }
                }
            }

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w - 1; j++) {
                    System.out.print(ans[i][j] + " ");
                }
                System.out.println(ans[i][w - 1]);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
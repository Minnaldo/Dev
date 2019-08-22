import java.io.*;
import java.util.StringTokenizer;

/**
 *  * 최장 공통 부분 수열
 */

public class SWEA_3304 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;

                StringTokenizer st = new StringTokenizer(br.readLine());
                String str1 = st.nextToken();
                String str2 = st.nextToken();

                int size = str1.length();
                int size2 = str2.length();

                int[][] map = new int[size + 1][size2 + 1];
                for (int i = 1; i <= size; i++) {
                    for (int j = 1; j <= size2; j++) {
                        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                            map[i][j] = map[i - 1][j - 1] + 1;
                        } else {
                            map[i][j] = map[i - 1][j] > map[i][j - 1] ? map[i - 1][j] : map[i][j - 1];
                        }
                    }
                }

                ans = map[size][size2];

                System.out.println("#" + tc + " " + ans);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
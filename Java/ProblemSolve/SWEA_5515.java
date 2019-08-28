import java.io.*;
import java.util.StringTokenizer;

public class SWEA_5515 {

    static int[] dayofMonth = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                StringTokenizer st = new StringTokenizer(br.readLine());

                int m = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());
                int a = 4;
                loop: for (int i = 1; i <= m; i++) {
                    for (int j = 1; j <= dayofMonth[i]; j++) {
                        ans = a % 7;
                        a++;
                        if (i == m && j == d) {
                            break loop;
                        }
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.util.StringTokenizer;

public class SWEA_4299 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                StringTokenizer st = new StringTokenizer(br.readLine());

                int d = Integer.parseInt(st.nextToken());
                int h = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());


                ans = m - 11;
                ans += (h - 11) * 60;
                ans += (d - 11) * (60 * 24);

                if( ans < 0 ){
                    ans = -1;
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
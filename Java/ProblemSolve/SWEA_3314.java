import java.io.*;
import java.util.StringTokenizer;

public class SWEA_3314 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                int sum = 0;
                while (st.hasMoreTokens()) {
                    int tmp = Integer.parseInt(st.nextToken());
                    if (tmp < 40) {
                        sum += 40;
                    } else {
                        sum += tmp;
                    }
                }

                System.out.println("#" + tc + " " + sum / 5);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
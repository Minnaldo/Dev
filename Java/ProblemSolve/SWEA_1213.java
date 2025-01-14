import java.io.*;

public class SWEA_1213 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            for (int tc = 1; tc <= 10; tc++) {
                int ans = 0;
                int t = Integer.parseInt(br.readLine());
                String str = br.readLine();
                StringBuilder sb = new StringBuilder(br.readLine());

                int idx = 0;
                while (idx != -1) {
                    idx = sb.indexOf(str, idx + 1);
                    ans++;
                }

                System.out.println("#" + tc + " " + (ans - 1));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.util.StringTokenizer;

public class SWEA_1244 {

    static int exchange, ans;

    static void swap(StringBuilder sb, int idx, int idx2) {
        char tmp = sb.charAt(idx);
        sb.setCharAt(idx, sb.charAt(idx2));
        sb.setCharAt(idx2, tmp);
    }

    static void func(StringBuilder sb, int cnt) {
        if (cnt == exchange) {
            int tmp = Integer.parseInt(sb.toString());
            ans = Math.max(ans, tmp);
            return;
        }

        // 조건을 이용해 스왑
        for (int i = 0; i < sb.length(); i++) {
            for (int j = i + 1; j < sb.length(); j++) {
                if (i == j || sb.charAt(i) == sb.charAt(j))
                    continue;
                if (Character.digit(sb.charAt(i), 10) < Character.digit(sb.charAt(j), 10)) {
                    swap(sb, i, j);
                    func(sb, cnt + 1);
                    swap(sb, i, j);
                }
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                StringBuilder sb = new StringBuilder(st.nextToken());
                exchange = Integer.parseInt(st.nextToken());

                ans = Integer.parseInt(sb.toString());
                func(sb, 0);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
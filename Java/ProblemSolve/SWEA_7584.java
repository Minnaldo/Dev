import java.io.*;

public class SWEA_7584 {

    static StringBuilder sb;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {

                int n = Integer.parseInt(br.readLine());
                sb = new StringBuilder("0"); // p0

                StringBuilder sb2 = null;
                for (int i = 0; i < n; i++) {
                    sb2 = new StringBuilder(sb);
                    sb.append("0");
                    for (int j = 0; j < sb2.length(); j++) {
                        if (sb2.charAt(j) == '0') {
                            sb.append("1");
                        } else {
                            sb.append("0");
                        }
                    }
                    sb2.setLength(0);
                }
                System.out.println(sb.toString());

                char ans = sb.charAt(n-1);
                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;

public class SWEA_7584 {

    static StringBuilder sb = new StringBuilder("0"); // p0

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {

                int n = Integer.parseInt(br.readLine());

                int k = (int) ((n) / 2 + 0.5);

                for (int i = 0; i < 3000; i++) {
                    char[] ch = new StringBuilder(sb).reverse().toString().toCharArray();
                    sb.append("0");
                    for (int j = 0; j < ch.length; j++) {
                        sb.append(ch[j] == '1' ? 0 : 1);
                    }
                }

                System.out.println(sb.toString());

                char ans = sb.charAt(n - 1);
                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
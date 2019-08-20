import java.io.*;
import java.util.StringTokenizer;

/**
 * 통역사 성경이
 */

public class SWEA_7675 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                String ans = null;
                int n = Integer.parseInt(br.readLine());
                StringTokenizer st = new StringTokenizer(br.readLine());
                StringBuilder sb = new StringBuilder();
                int cnt = 0;
                while (st.hasMoreTokens()) {
                    String str = st.nextToken();
                    int size = str.length();
                    boolean exitFlag = false;
                    if (str.contains("!") || str.contains("?") || str.contains(".")) {
                        exitFlag = true;
                    }

                    if (str.charAt(0) - 'A' >= 0 && str.charAt(0) - 'A' <= 25) {
                        boolean flag = false;
                        if (exitFlag)
                            size--;
                        for (int i = 1; i < size; i++) {
                            if (!(str.charAt(i) - 'a' >= 0 && str.charAt(i) - 'a' <= 25)) {
                                flag = true;
                                // break;
                            }
                        }

                        if (!flag) {
                            cnt++;
                        }
                    }

                    if (exitFlag) {
                        sb.append(cnt).append(" ");
                        cnt = 0;
                    }
                }
                System.out.println("#" + tc + " " + sb.toString().trim());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;

/**
 * 비밀이메일
 *  실수 : r과 c를 정할 때 잘못 정했다
 */

public class Baek_2999 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringBuilder sb = new StringBuilder(br.readLine());
            int len = sb.length();

            int r = 0, c = 0;
            for (int i = 1; i <= len; i++) {
                for (int j = 1; j <= i; j++) {
                    if (i * j == len) {
                        if (r < j) {
                            r = j;
                            c = i;
                        }
                    }
                }
            }

            char[][] msg = new char[r][c];

            int idx = 0;
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < r; j++) {
                    if (idx < len)
                        msg[j][i] = sb.charAt(idx++);
                }
            }

            sb = new StringBuilder();
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    sb.append(msg[i][j]);
                }
            }

            System.out.println(sb.toString().trim());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
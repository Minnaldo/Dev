import java.io.*;
import java.util.*;

/**
 *  회문 1 : n길이의 회문이 몇개인지 찾는 문제
 */

public class SWEA_1215 {
    static boolean find(String str) {
        int offset = str.length() / 2;
        int start = 0, end = str.length() - 1;
        boolean flag = true;
        for (int i = 0; i < offset; i++) {

            if (str.charAt(start) == str.charAt(end)) {
                start++;
                end--;
            } else {
                flag = false;
                break;
            }

        }
        return flag;
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            for (int tc = 1; tc <= 10; tc++) {
                int len = Integer.parseInt(br.readLine());
                int ans = 0;
                String[] map = new String[8];
                for (int i = 0; i < 8; i++) {
                    map[i] = br.readLine();
                }

                // 가로에서 찾는다
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8 - len+1; j++) {
                        if (find(map[i].substring(j, j + len))) {
                            ans++;
                        }
                    }
                }
                // 세로에서 찾는다
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8 - len+1; j++) {
                        for (int k = j; k < j + len; k++) {
                            sb.append(map[k].charAt(i));
                        }
                        if (find(sb.toString()))
                            ans++;
                        sb.setLength(0);
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.util.*;

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
            for (int tc = 1; tc <= 1; tc++) {
                int len = Integer.parseInt(br.readLine());
                int ans = 0;
                String[] map = new String[8];
                for (int i = 0; i < 8; i++) {
                    map[i] = br.readLine();
                }

                // 가로에서 찾는다
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8 - len; j++) {
                        if (find(map[i].substring(j, j + len))) {
                            ans++;
                        }
                    }
                }

                // 세로에서 찾는다
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8 - len; j++) {
                        String str = "";
                        for (int k = j; k < j + len; k++) {
                            str += map[j].charAt(i);
                        }
                        if (find(str)) {
                            ans++;
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
import java.io.*;
import java.util.StringTokenizer;

/**
 *  늘어지는 소리 만들기
 */

public class SWEA_4676 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                StringBuilder str = new StringBuilder(br.readLine());
                int n = Integer.parseInt(br.readLine());
                StringTokenizer st = new StringTokenizer(br.readLine());

                while (st.hasMoreTokens()) {
                    int index = Integer.parseInt(st.nextToken());
                    int inputIdx = 0;
                    int cnt = 0;
                    for (int i = 0; i < str.length(); i++) {
                        int tmp = str.charAt(i) - 'a';
                        if (tmp >= 0 && tmp <= 26) {
                            cnt++;
                        }
                        if (cnt == index ) {
                            inputIdx = i+1;
                        }
                    }
                    str.insert(inputIdx, "-");
                }

                System.out.println("#" + tc + " " + str.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
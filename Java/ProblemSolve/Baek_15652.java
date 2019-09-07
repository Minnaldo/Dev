import java.io.*;
import java.util.*;

/** N 과 M (4)
 *  * 1 부터 N까지 자연수 중에서 M개를 고른 수열
 *  * 같은 수를 여러번 골라도 된다 ==> 중복을 허용한다
 *  * 고른 수열은 비내림차순 이어야 한다 --> 오름차순 정렬이 되어있어야 한다.
 *  TODO need some summary for this problem
 */

public class Baek_15652 {

    static int n, m;
    static StringBuilder sb;
    static BufferedWriter bw;

    static void func(int[] sel, int idx) throws Exception {
        if (idx == sel.length) {
            sb = new StringBuilder();
            for (int val : sel) {
                sb.append(val).append(" ");
            }
            bw.write(sb.toString().trim());
            bw.write("\n");
            return;
        }

        for (int i = sel[idx - 1]; i <= n; i++) {
            sel[idx] = i;
            func(sel, idx + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            int[] sel = new int[m];
            sel[0] = i;
            func(sel, 1);
        }
        bw.flush();
    }
}
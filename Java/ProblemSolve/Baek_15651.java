import java.io.*;
import java.util.*;

/** N 과 M (3)
 *  * 1 부터 N까지 자연수 중에서 M개를 고른 수열
 *  * 같은 수를 여러번 골라도 된다.
 *  * 같은 수를 여러번 고르는 수열의 종류는 2가지, (중복 순열, 중복 조합)
 *  * 그러나 예시에서, 요소는 같으나 순서가 다르면, 출력이 되어있음
 *  * ==> 이는 중복순열을 뜻하는 것
 *  * 중복순열은 매 시행에서 모두를 뽑을 수 있다
 */

public class Baek_15651 {

    static int[] arr;
    static StringBuilder sb;
    static Vector<String> vec;

    static void re_perm(int[] sel, int idx, int n) {
        if (sel.length == idx) {
            sb = new StringBuilder();
            for (int val : sel) {
                sb.append(val).append(" ");
            }
            vec.add(sb.toString().trim());
            return;
        }

        for (int i = 0; i < n; i++) {
            sel[idx] = arr[i];
            re_perm(sel, idx + 1, n);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        vec = new Vector<>();

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        re_perm(new int[m], 0, n);
        Collections.sort(vec);

        for (String val : vec) {
            bw.write(val);
            bw.write("\n");
        }

        bw.flush();
    }
}
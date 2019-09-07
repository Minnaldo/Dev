import java.io.*;
import java.util.*;

/** N과 M  (2)
 *  * 1 부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 ( Permutation; 순열 )
 *  * 중복이 없어야 하므로, 이전에 골랐던 요소는 체크(visit배열 이용)를 해서 고르지 못하도록 한다
 */

public class Baek_15650 {

    static HashSet<String> set = new HashSet<>();
    static int n;

    static void perm(int[] arr, boolean[] visit, int idx, int[] sel) {
        if (idx == sel.length) {
            StringBuilder sb = new StringBuilder();
            for (int val : sel) {
                sb.append(val).append(" ");
            }

            set.add(sb.toString().trim());
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                sel[idx] = arr[i];
                perm(arr, visit, idx + 1, sel);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        perm(arr, new boolean[n], 0, new int[m]);
        Vector<String> vec = new Vector<>(set);

        Collections.sort(vec);

        for (String val : vec) {
            boolean flag = true;
            String tmp = val.replaceAll(" ", "");
            for (int i = 1; i < m; i++) {
                if ((tmp.charAt(i) - '0') - (tmp.charAt(i - 1) - '0') <= 0) {
                    flag = false;
                }
            }

            if (flag)
                bw.write(val + "\n");
        }
        bw.flush();
    }
}
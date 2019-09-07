import java.io.*;
import java.util.*;

/** N과 M  (2)
 *  * 1 부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 *  * 중복이 없어야 하므로, 이전에 골랐던 요소는 체크(visit배열 이용)를 해서 고르지 못하도록 한다
 */

public class Baek_15655 {
    static int n, m;
    static StringBuilder sb;

    static void func(int[] arr, int[] sel, boolean[] visit, int idx) {
        if (idx == sel.length) {
            sb = new StringBuilder(sel[0] + " ");
            for (int i = 1; i < idx; i++) {
                if (sel[i - 1] >= sel[i])
                    return;
                else {
                    sb.append(sel[i]).append(" ");
                }
            }
            System.out.println(sb);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                sel[idx] = arr[i];
                func(arr, sel, visit, idx + 1);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(arr);
            func(arr, new int[m], new boolean[n], 0);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
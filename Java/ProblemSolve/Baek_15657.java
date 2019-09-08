import java.io.*;
import java.util.*;

/** n 과 m (8)
 *
 */

public class Baek_15657 {

    static StringBuilder sb = new StringBuilder();
    static int n, m;
    static int[] arr;

    static void func(int[] sel, int k) {
        if (k == sel.length) {
            for (int i = 0; i < m; i++) {
                sb.append(sel[i] + " ");
            }
            sb.append("\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] >= sel[k - 1]) {
                sel[k] = arr[i];
                func(sel, k + 1);
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);

            for (int i = 0; i < n; i++) {
                int[] sel = new int[m];
                sel[0] = arr[i];
                func(sel, 1);
            }

            System.out.println(sb.toString());

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.util.*;

public class Baek_15654 {

    static StringBuilder sb;
    static int n, m;

    static void combi(int[] arr, int[] sel, int k, int idx, boolean[] visit) {
        if (idx == sel.length) {
            sb = new StringBuilder();
            for (int val : sel) {
                sb.append(val).append(" ");
            }
            System.out.println(sb.toString());
            return;
        }

        if (k == arr.length) {
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                sel[idx] = arr[i];
                visit[i] = true;
                combi(arr, sel, k + 1, idx + 1, visit);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            int[] arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            combi(arr, new int[m], 0, 0, new boolean[n]);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
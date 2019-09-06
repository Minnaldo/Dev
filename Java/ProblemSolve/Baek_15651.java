import java.io.*;
import java.util.*;

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
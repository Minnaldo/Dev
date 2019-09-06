import java.io.*;
import java.util.*;

// 얘는 조합인가?
// TODO

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
import java.io.*;
import java.util.*;

public class Baek_15663 {
    static StringBuilder sb;
    static int n, m;
    static int[] arr;
    static Vector<String> vec = new Vector<>();
    static HashSet<String> set = new HashSet<>();

    static void func(int[] sel, boolean[] visit, int k) {
        if (k == sel.length) {
            sb = new StringBuilder();
            for (int i = 0; i < sel.length; i++) {
                sb.append(sel[i]).append(" ");
            }
            set.add(sb.toString().trim());
            return;
        }

        for (int i = 0; i < n; i++)
            if (!visit[i]) {
                sel[k] = arr[i];
                visit[i] = true;
                func(sel, visit, k + 1);
                visit[i] = false;
            }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        func(new int[m], new boolean[n], 0);
        vec = new Vector<>(set);
        Collections.sort(vec);

        for (String ss : vec) {
            System.out.println(ss);
        }
    }
}
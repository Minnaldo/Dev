import java.io.*;
import java.util.*;

public class Baek_15663 {
    static StringBuilder sb = new StringBuilder();
    static int n, m;
    static int[] arr;
    static Vector<String> vec = new Vector<>();

    static void func(StringBuilder sel, boolean[] visit, int k) {
        if (k == sel.length()) {
            if (!vec.contains(sel.toString().trim()))
                vec.add(sel.toString().trim());
            return;
        }

        for (int i = 0; i < n; i++)
            if (!visit[i]) {
                sb.append(arr[i]).append(" ");
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

        func(new StringBuilder(), new boolean[n], 0);
        Collections.sort(vec);

        for (String ss : vec) {
            System.out.println(ss);
        }
    }
}
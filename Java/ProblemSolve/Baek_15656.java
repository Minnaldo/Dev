import java.io.*;
import java.util.*;

public class Baek_15656 {
    static int n, m;
    static StringBuilder sb = new StringBuilder();

    static void func(int[] arr, int idx, int[] sel) {
        if (idx == m) {
            for (int i = 0; i < m; i++) {
                sb.append(sel[i]).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            sel[idx] = arr[i];
            func(arr, idx + 1, sel);
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

            func(arr, 0, new int[m]);
            System.out.println(sb);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.util.*;

public class Baek_2407 {

    static int n, r;

    static HashSet<String> set = new HashSet<>();
    static StringBuilder sb = new StringBuilder();

    static void combi(int[] arr, int k, int idx, int[] sel) {
        if (idx == sel.length) {
            Arrays.sort(sel);
            // System.out.println(Arrays.toString(sel));
            sb.append(sel);
            set.add(sb.toString());
            // System.out.println(set.toString());
            sb.setLength(0);
            return;
        }
        if (k == n) {
            return;
        }

        // 현재 시행에서 r번째 인덱스를 뽑고 안뽑고
        sel[idx] = arr[k];
        combi(arr, k + 1, idx + 1, sel);
        combi(arr, k + 1, idx, sel);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }

            combi(arr, 0, 0, new int[r]);
            System.out.println(set.size());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
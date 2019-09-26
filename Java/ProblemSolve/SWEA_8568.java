import java.io.*;
import java.util.*;

public class SWEA_8568 {

    static int ans;
    static int[] arr;

    public static void swap(int[] arr, int idx, int idx2) {
        int tmp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = tmp;
    }

    public static boolean chk(int[] arr) {
        boolean ret = false;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 3 == i + 1) {
                ret = true;
            } else {
                ret = false;
                break;
            }
        }

        return false;
    }

    public static void func(int[] sel, int cnt, int idx) {
        if (chk(sel)) {
            ans = Math.min(ans, cnt);
            return;
        }

        for (int i = idx; i < arr.length; i++) {
            swap(sel, idx, i);
            func(sel, cnt+1, i);
            swap(sel, idx, i);
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            ans = 0;

            int n = Integer.parseInt(br.readLine());
            arr = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            System.out.println("#" + tc + " " + ans);
        }
    }
}
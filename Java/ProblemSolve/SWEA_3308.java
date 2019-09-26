import java.io.*;
import java.util.*;

public class SWEA_3308 {
    static int[] arr;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = Integer.parseInt(br.readLine());
            arr = new int[n];

            ArrayList<Integer> result = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            result.add(arr[0]);

            for (int i = 1; i < n; i++) {
                if (result.get(result.size() - 1) < arr[i]) {
                    result.add(arr[i]);
                } else {
                    int tmp = lower(result, arr[i], 0, result.size());
                    result.set(tmp, arr[i]);
                }
            }
            System.out.println("#" + tc + " " + result.size());
        }
    }

    static public int lower(ArrayList<Integer> arr, int key, int start, int end) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr.get(mid) < key) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return end;
    }
}
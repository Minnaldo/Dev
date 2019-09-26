import java.io.*;
import java.util.*;

public class SWEA_3307_2 {
    static int[] arr, result;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = Integer.parseInt(br.readLine());

            arr = new int[n + 1];
            result = new int[n + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            result[1] = 1;
            for (int i = 2; i <= n; i++) {
                int tmp = 0;
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j]) {
                        tmp = Math.max(tmp, result[j]);
                    }
                }
                result[i] = tmp + 1;
                ans = Math.max(ans, result[i]);
            }

            System.out.println("#" + tc + " " + ans);
        }

    }
}
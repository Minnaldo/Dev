import java.io.*;
import java.util.*;

public class Baek_11055 {

    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        int ans = 0, tmpSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cur = arr[i];
            tmpSum = cur;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < cur) {
                    tmpSum += arr[j];
                    cur = arr[j];
                }
            }
            ans = Math.max(ans, tmpSum);
        }

        System.out.println(ans);
    }
}
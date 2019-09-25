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

        int[] tmp = new int[n];
        tmp[0] = arr[0];
        int idx = 1;
        for (int i = 1; i < n; i++) {
            int tmpSum = 0;
            for (int j = 0; j < i; j++) {
                tmpSum += arr[j];
                if (tmp[j] < arr[i]) {
                    if (tmpSum < tmpSum - tmp[j] + arr[i]) {
                        tmp[j] = arr[i];
                        tmpSum += (arr[i] - tmp[j]);
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < idx; i++) {
            ans += tmp[i];
        }

        System.out.println(ans);
    }
}
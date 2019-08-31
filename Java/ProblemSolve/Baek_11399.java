import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baek_11399 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            int[] sum = new int[n];
            Arrays.sort(arr);
            sum[0] = arr[0];
            int ans = sum[0];
            for (int i = 1; i < arr.length; i++) {
                sum[i] = sum[i - 1] + arr[i];
                ans += sum[i];
            }

            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
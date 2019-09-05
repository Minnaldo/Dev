import java.io.*;
import java.util.StringTokenizer;

public class Baek_1547 {
    static boolean[] arr = new boolean[4];

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int m = Integer.parseInt(br.readLine());

            arr[1] = true;
            StringTokenizer st;
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                swap(arr, a, b);
            }
            int ans = 0;
            for (int i = 1; i <= 3; i++) {
                if (arr[i])
                    ans = i;
            }

            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void swap(boolean[] arr, int a, int b) {
        boolean tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
}
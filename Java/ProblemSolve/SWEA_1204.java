import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;

public class SWEA_1204 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 1;
                int n = Integer.parseInt(br.readLine());
                StringTokenizer st = new StringTokenizer(br.readLine());

                int[] arr = new int[101];
                while (st.hasMoreTokens()) {
                    arr[Integer.parseInt(st.nextToken())]++;
                }

                for (int i = 2; i <= 100; i++) {
                    ans = arr[ans] > arr[i] ? ans : i;
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
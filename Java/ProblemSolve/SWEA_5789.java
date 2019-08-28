import java.io.*;
import java.util.StringTokenizer;

public class SWEA_5789 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int q = Integer.parseInt(st.nextToken());
                int[] arr = new int[n + 1];
                int num = 1;
                for (int i = 0; i < q; i++) {
                    st = new StringTokenizer(br.readLine());
                    int l = Integer.parseInt(st.nextToken());
                    int r = Integer.parseInt(st.nextToken());

                    for (int j = l; j <= r; j++) {
                        arr[j] = num;
                    }
                    num++;
                }

                bw.write("#" + tc + " ");
                for (int i = 1; i <= n; i++) {
                    bw.write(arr[i] + " ");
                }
                bw.write("\n");
                bw.flush();

            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
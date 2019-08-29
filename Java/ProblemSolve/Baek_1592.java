import java.io.*;
import java.util.StringTokenizer;

public class Baek_1592 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());

            int[] arr = new int[n];
            int idx = 0;
            while (true) {
                if (arr[idx] == 5) {
                    break;
                }
                if ((idx + 1) % 2 == 0) {
                    // 오른쪽으로, 반시계 방향
                    idx += l;
                    idx %= n;
                } else {
                    // 왼쪽으로, 시계 방향
                    if (idx > l) {
                        idx -= l;
                    } else {
                        idx = n - (l - idx);
                    }
                }
                arr[idx]++;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(arr[i]).append(" ");
            }

            bw.write(sb.toString().trim());
            bw.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
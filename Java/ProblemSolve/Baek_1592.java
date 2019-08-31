import java.io.*;
import java.util.StringTokenizer;

/**
 *  영식이와 친구들
 */


public class Baek_1592 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());

            int[] arr = new int[n];
            int idx = 0;
            arr[idx] = 1;
            while (true) {

                if (arr[idx] == m) {
                    break;
                }

                // 받은 횟수가 짝수번
                if (arr[idx] % 2 == 0) {
                    // 반시계 방향
                    if (idx >= l) {
                        idx -= l;
                    } else {
                        idx = n - (l - idx);
                    }
                } else {
                    // 시게방향
                    idx += l;
                    if (idx >= n)
                    idx = (idx % n);
                }
                System.out.println("idx=" + idx);
                arr[idx]++;
            }
            StringBuilder sb = new StringBuilder();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
            }

            System.out.println(sum-1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
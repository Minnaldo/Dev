import java.io.FileInputStream;
import java.util.*;

public class SWEA_1859 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(fis);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            long[] arr = new long[n];
            long ans = 0l; // 답을 저장할 배열

            // data input
            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();

            // Problem Solve
            long pivot = arr[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                if (pivot > arr[i]) {
                    // 배열에 삽입
                    ans += (pivot - arr[i]);
                } else {
                    pivot = arr[i];
                }
            }
            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
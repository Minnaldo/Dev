import java.util.*;

public class SWEA_1859 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            FileInputStream fis = new FileInputStream("input.txt");

            int t = fis.read();

            for (int tc = 1; tc <= t; tc++) {
                long ans = 0;
                int n = sc.nextInt();

                long[] arr = new long[n];
                long[] tmp = new long[n]; // 값들을 저장
                for (int i = 0; i < n; i++) {
                    arr[i] = sc.nextInt();
                }

                for (int i = n - 1; i >= 0; i--) {
                    long sum = 0;
                    for (int j = 0; j < i - 1; j++) {
                        if (arr[i] > arr[j]) {
                            sum += arr[i] - arr[j];
                        }
                    }
                    tmp[i] = sum;
                }

                // 최댓값을 구한다
                ans = tmp[0];
                for (int i = 1; i < n; i++) {
                    ans = ans > tmp[i] ? ans : tmp[i];
                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;

/**
 * 이분탐색을 이용해 원하는 길이보다 작은 수 중, 가장 큰 막대 길이를 가져온다
 *  NOTE
 */

public class Baek_1094 {

    static int[] arr = { 1, 2, 4, 8, 16, 32, 64 };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int x = Integer.parseInt(br.readLine());
            int ans = 0;
            while (x > 0) {
                int left = 0, right = arr.length - 1;
                int mid = 0;
                int key = x;
                while (left <= right) {
                    // 이분탐색
                    mid = (left + right) / 2;
                    if (arr[mid] > key) {
                        right = mid - 1;
                    } else if (arr[mid] < key) {
                        left = mid + 1;
                    } else {
                        right = mid;
                        break;
                    }
                }

                x -= arr[right];
                ans++;
            }

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
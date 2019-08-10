/** 건초 더미
 *  * 같은높이가 되려면 모든 건초더미 합의 평균이 되어야 한다.
 *  * 움직이려면 높은 더미에서 낮은 더미로 옮길 때 횟수가 1 증가
 *  * 평균 보다 낮은 높이의 더미를 평균으로 만드는 횟수를 구하면 된다
 *  * 즉, 평균높이 - 평균보다 낮은 높이의 더미 를 합한 것과 같다.
 */


import java.io.*;
import java.util.Arrays;

public class Solution {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = Integer.parseInt(br.readLine());

                int[] arr = new int[n];
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    arr[i] = Integer.parseInt(br.readLine());
                    sum += arr[i];
                }

                Arrays.sort(arr);
                int avg = sum / n;
                for (int i = 0; i < n; i++) {
                    if (arr[i] < avg) {
                        ans += (avg - arr[i]);
                    } else
                        break;
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
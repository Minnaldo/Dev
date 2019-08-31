
/** SWEA_1208 Flatten
 *
 */

import java.util.*;

class SWEA_1208 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int tc = 1; tc <= 10; tc++) {
            int dump = sc.nextInt();
            int[] arr = new int[100];
            int ans = 0;

            for (int i = 0; i < 100; i++)
                arr[i] = sc.nextInt();

            Arrays.sort(arr);
            while (dump-- > 0) {
                Arrays.sort(arr);
                arr[99]--;
                arr[0]++;
            }
            Arrays.sort(arr);

            ans = arr[99] - arr[0];

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
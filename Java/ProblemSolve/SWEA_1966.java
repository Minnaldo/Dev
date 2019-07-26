/**
 *  * 숫자를 정렬하자!
 */

import java.util.*;

public class SWEA_1966 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);
            System.out.print("#" + tc + " ");
            for (int i = 0; i < n - 1; i++) {

                System.out.print(arr[i] + " ");
            }
            System.out.print(arr[n - 1]);
        }
        sc.close();
    }
}
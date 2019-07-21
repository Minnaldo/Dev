/** Gravity
 *  상자가 쌓여있는 방을 회전하였을 때, 가장 높은 곳에서 떨어지는 상자는 어느 높이를 떨어지는지 알아내는 문제
 */


import java.util.*;

public class gravity_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;

        int[] arr = new int[n];
        for(int i = 0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] != 0)
                    sum += arr[i] > arr[j] ? 1 : 0;
            }
            ans = ans > sum ? ans : sum;
        }
        System.out.print("가장 큰 낙차는 ");
        System.out.println(ans + " 입니다.");

        sc.close();
    }
}
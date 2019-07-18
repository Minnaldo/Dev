/** SWEA_5431 민석이의 과제 체크하기
 *
 */

import java.util.*;

public class SWEA_5431 {
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int tc = 1; tc<=t; tc++){
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n+1];
            for(int i = 0; i<k; i++)
                arr[sc.nextInt()]++;

            System.out.print("#"+tc+" ");
            for(int i = 1; i<n; i++)
            {
                if(arr[i] == 0)
                    System.out.print((i) + " ");
            }
            if(arr[n] == 0)
                System.out.println(n);
            else
                System.out.println();
        }
        sc.close();
    }
}
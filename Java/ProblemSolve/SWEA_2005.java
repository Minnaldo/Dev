/** SWEA_2005 파스칼의 삼각형
 *  파스칼의 삼각형을 구하는 문제
 */

import java.util.*;

public class SWEA_2005 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int tc = 1; tc<=t; tc++){
            int n = sc.nextInt();

            int[][] arr = new int[n+1][n+1];
            arr[1][1] = 1;
            for(int  i = 2; i<= n; i++)
                for(int j = 1; j<=n; j++)
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];

            System.out.println("#"+tc);

            for(int i = 1; i<=n;i++){
                for(int val : arr[i]){
                    if(val != 0)
                        System.out.print(val + " ");
                }
                System.out.println();
            }

        }
        sc.close();
    }
}
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class solv2 {
    static int max = 0;

    public static void recur(int[][] arr, idx, taste_sum, cal_sum){

        if(idx == arr.length)
        {
            max = max< cal ? cal : max;
            break;
        }

        recur(arr);
        recur(arr);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = 0, l = 0;
            n = sc.nextInt();
            l = sc.nextInt();

            int[][] arr = new int[2][n];

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }

            recur();
            recur();


            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
import java.util.Scanner;

/**
 *  일차원 배열만으로 해결 가능 함
 *  내 밑으로 arr[i] 보다 작거나 같은 값을 갖는 인덱스의 수를 n에서 뺀다
 */

public class gravity {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[][] map = new boolean[n][n];
        int[][] cnt = new int[n][n];

        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            for (int j = 0; j < num; j++)
                map[i][j] = true;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int k = i; k >= 0; k--) {
                    if (map[k][j]) {
                        map[i][j] = true;
                        map[k][j] = false;
                        cnt[i][j] = i-k;
                        break;
                    }
                }
            }
        }


        int ans = 0;
        for (int[] aa : cnt) {
            for (int val : aa) {
                ans = ans > val ? ans : val;
                System.out.print(val+" ");
            }
            System.out.println();
        }

        System.out.print("가장 큰 낙차는 : ");
        System.out.println(ans);
    }
}
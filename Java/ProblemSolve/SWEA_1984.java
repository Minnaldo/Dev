
/**
 *  ! 나눌땐 소수로 나누어 반올림을 한다
 *  * 반올림을 할 때, 0.5를 더한후 (int) 캐스팅을 하면 더 편한다
 */

import java.util.*;

public class SWEA_1984 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;

            int max = -9999, min = 987654321, sum = 0;
            for (int i = 0; i < 10; i++) {
                int tmp = sc.nextInt();
                max = max > tmp ? max : tmp;
                min = min < tmp ? min : tmp;
                sum += tmp;
            }

            ans = (int) (((sum - max - min) / 8.0) + 0.5);

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
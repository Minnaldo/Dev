
/**  SWEA_5549 홀수일까 짝수일까    (https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWxpEDaAVoDFAW4&categoryId=AWWxpEDaAVoDFAW4&categoryType=CODE)
 *  * BingInteger까지 필요 없다
 */

import java.util.*;

class SWEA_5549 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {

            String str = sc.next(), ans = null;

            if (Character.digit(str.charAt(str.length() - 1), 10) % 2 == 1)
                ans = "Odd";
            else
                ans = "Even";

            System.out.println("#" + tc + " " + ans);
        }
    }
}
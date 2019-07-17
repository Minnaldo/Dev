
/**  SWEA_5549 홀수일까 짝수일까    (https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWxpEDaAVoDFAW4&categoryId=AWWxpEDaAVoDFAW4&categoryType=CODE)
 *  * 입력받는 숫자가 매우 큰 숫자이므로 BigInteger를 사용해야함
 */

import java.math.BigInteger;
import java.util.*;

class SWEA_5549 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        BigInteger aa, bb;

        for (int tc = 1; tc <= t; tc++) {
            String str, tmp = sc.next();
            aa = new BigInteger(tmp, 10);
            bb = new BigInteger("2", 10);

            if (aa.mod(bb).intValue() == 1)
                str = "Odd";
            else
                str = "Even";

            System.out.println("#" + tc + " " + str);
        }
    }
}
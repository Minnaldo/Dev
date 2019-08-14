import java.io.FileInputStream;
import java.util.*;

/**
 * * 연산자의 갯수가 피연산자의 수 이상이면 안된다.
 */

public class SWEA_1233 {

    public static boolean isStringtoInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int tc = 1; tc <= 10; tc++) {
            int n = sc.nextInt();
            String[] arr = new String[n + 1];

            sc.nextLine();
            int numCnt = 0, operCnt = 0;
            for (int i = 1; i <= n; i++) {
                String[] input = sc.nextLine().split(" ");
                arr[Integer.parseInt(input[0])] = input[1];
                if (isStringtoInteger(arr[i])) {
                    numCnt++;
                } else {
                    operCnt++;
                }
            }
            int ans = numCnt > operCnt ? 1 : 0;
            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
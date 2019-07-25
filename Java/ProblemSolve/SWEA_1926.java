
/**
 *  3으로 먼저 나눠선 안된다. ex. 12
 */

import java.util.*;

public class SWEA_1926 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            if (!Integer.toString(i).contains("3") && !Integer.toString(i).contains("6")
                    && !Integer.toString(i).contains("9")) {
                System.out.print(i + " ");
            } else {
                String str = Integer.toString(i);
                // 박수
                for (int j = 0; j < str.length(); j++) {
                    if (str.charAt(j) == '3' || str.charAt(j) == '6' || str.charAt(j) == '9') {
                        System.out.print("-");
                    }
                }
                System.out.print(" ");
            }
        }
        sc.close();
    }
}
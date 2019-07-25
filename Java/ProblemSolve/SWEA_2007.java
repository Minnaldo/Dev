import java.util.*;

public class SWEA_2007 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            String str = sc.next();
            char fChar = str.charAt(0);
            int idx = 1;

            for (int i = 1; i < str.length(); i++) {
                if (fChar == str.charAt(i)) {
                    boolean flag = false;
                    for (int j = 0; j < idx; j++) {
                        if (str.charAt(j) != str.charAt(j + i)) {
                            flag = true;
                        }
                    }
                    if (!flag) {
                        ans = idx;
                        break;
                    }
                }
                idx++;
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
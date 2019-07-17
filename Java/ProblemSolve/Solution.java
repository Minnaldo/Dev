import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = -1;
            String inStr = sc.next();
            int size = inStr.length();
            char[] tmp = new char[size];

            String tmpStr="";
            while (!inStr.equals(tmpStr)) {
                char val = tmp[size - 1] == '0' ? '1' : '0';
                for (int i = size - 1; i >= 0; i--) {
                    // tmp 변경
                    if (val == tmp[i]) {
                        break;
                    }
                    tmp[i] = val;
                    tmpStr = String.valueOf(tmp);


                    if (inStr.equals(tmpStr)) {
                        break;
                    }
                }

                ans++;

                tmpStr = String.valueOf(tmp);
            }
            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
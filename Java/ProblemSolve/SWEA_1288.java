import java.util.*;
import java.io.*;

class SWEA_1288 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int num = sc.nextInt();
            int multiple = 1;
            boolean[] arr = new boolean[10];

            while (true) {
                int sheep = num * multiple;
                while (sheep > 0) {
                    arr[sheep % 10] = true;
                    sheep /= 10;
                }

                boolean flag = false;
                for (int i = 0; i < 10; i++) {
                    if (!arr[i]) {
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                    break;

                multiple++;
            }

            ans = multiple * num;

            System.out.println("#" + tc + " " + ans);
        } // end of for-loop

        sc.close();

    }
}
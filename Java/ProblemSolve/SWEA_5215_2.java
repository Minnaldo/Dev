import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA_5215_2 {

    static int limit;
    static int tmpTaste;

    static void recur(int[] tarr, int[] carr, int idx, int taste, int cal) {

        if (idx == tarr.length) {
            if (cal <= limit) {
                tmpTaste = tmpTaste > taste ? tmpTaste : taste;
            }
            return;
        }

        recur(tarr, carr, idx + 1, taste + tarr[idx], cal + carr[idx]);
        recur(tarr, carr, idx + 1, taste, cal);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            tmpTaste = 0;
            int n = sc.nextInt();
            limit = sc.nextInt();

            int[] tarr = new int[n];
            int[] carr = new int[n];

            for (int i = 0; i < n; i++) {
                tarr[i] = sc.nextInt();
                carr[i] = sc.nextInt();
            }

            recur(tarr, carr, 0, 0, 0);
            ans = tmpTaste;

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();

    }
}
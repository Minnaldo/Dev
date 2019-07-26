import java.util.*;
import java.io.*;

public class SWEA_1970 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int[] basePrice = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
            int size = basePrice.length;
            int[] ans = new int[size];
            int idx = 0;
            while (idx < size) {
                ans[idx] = n / basePrice[idx];
                n %= basePrice[idx];
                idx++;
            }

            System.out.println("#" + tc);
            for (int i = 0; i < size - 1; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println(ans[size - 1]);
        }
        sc.close();

    }
}
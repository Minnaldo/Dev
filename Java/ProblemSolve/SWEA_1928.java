import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class SWEA_1928 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            String str = sc.next();
            int size = str.length();
            // ArrayList<Integer> arr = new ArrayList<>();
            ArrayList<String> bit = new ArrayList<>();

            for(int i = 0; i<size; i++)
            {
                char tmpChar = str.charAt(i);
                bit.add(Integer.toBinaryString(tmpChar - '\0'));
            }

            // for(String aa : bit)
            // {
            //     System.out.println(aa);
            // }
            System.out.print("M to Binary : ");
            System.out.println(Integer.toBinaryString('M'));
            String tmp = "0"+Integer.toBinaryString('M');
            String aa = tmp.substring(0,6);
            String oct = Integer.valueOf(aa, 10);
            // System.out.println(oct);

            // Integer.valueOf(,10);

            // System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
import java.util.*;

public class SWEA_2019 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print((int)Math.pow(2, i)+" ");
        }
        System.out.println((int)Math.pow(2,n));

        sc.close();
    }
}
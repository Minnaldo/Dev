import java.util.Scanner;

public class SWEA_2070 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int be = sc.nextInt();
            int af = sc.nextInt();

            String str = be == af ? "=" : be > af ? ">" : "<";

            System.out.println("#" + tc + " " + str);
        }
        sc.close();
    }
}
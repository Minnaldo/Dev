import java.util.Scanner;

class pro1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int div, mod;
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();

            div = a / b;
            mod = a % b;

            System.out.println("#" + tc + " " + div +" "+ mod);
        }
    }
}
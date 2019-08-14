import java.util.Scanner;

public class SWEA_4406 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            String tmp = sc.next();

            tmp = tmp.replaceAll("a", "").replaceAll("e", "").replaceAll("i", "").replaceAll("o", "").replaceAll("u",
                    "");

            System.out.println("#" + tc + " " + tmp);
        }
        sc.close();
    }
}
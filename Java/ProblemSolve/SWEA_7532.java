import java.util.Scanner;

public class SWEA_7532 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;

            int s = sc.nextInt();
            int e = sc.nextInt();
            int m = sc.nextInt();

            int year = 0, month = 0, day = 0;

            while (!(s == year && e == month && day == m)) {
                ans++;
                year = ++year == 366 ? 1 : year;
                month = ++month == 25 ? 1 : month;
                day = ++day == 30 ? 1 : day;
            }

            System.out.println("#" + tc + " " + ans);
        }

    }
}
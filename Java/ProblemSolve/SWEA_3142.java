import java.util.Scanner;

public class SWEA_3142 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {

            int n = sc.nextInt();
            int m = sc.nextInt();

            int tmpTwin = n / 2;
            int tmpUni = m - tmpTwin;

            while (!(tmpTwin + tmpUni == m && (tmpTwin * 2) + tmpUni == n)) {
                tmpTwin--;
                tmpUni++;
            }

            System.out.println("#" + tc + " " + tmpUni + " " + tmpTwin);
        }
        sc.close();
    }
}
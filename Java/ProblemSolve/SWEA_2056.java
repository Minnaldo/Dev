import java.util.*;

public class SWEA_2056 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            String ans = "";
            String date = sc.next();

            String year = date.substring(0, 4);
            String wol = date.substring(4, 6);
            String il = date.substring(6);
            date = year + "/" + wol + "/" + il;
            int month = Integer.parseInt(wol);
            int day = Integer.parseInt(il);

            if (month >= 1)
                if (month <= 8) {
                    if (month % 2 == 1) {
                        ans = day <= 31 ? date : "-1";
                    } else {
                        if (month != 2)
                            ans = day <= 30 ? date : "-1";
                        else
                            ans = day <= 28 ? date : "-1";
                    }
                } else {
                    if (month % 2 == 1) {
                        ans = day <= 30 ? date : "-1";
                    } else {
                        ans = day <= 31 ? date : "-1";
                    }
                }
            else
                ans = "-1";

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
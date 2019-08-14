import java.io.FileInputStream;
import java.util.Scanner;

/**
 *  TODO
 */

public class SWEA_6730 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int n = sc.nextInt();
                int[] arr = new int[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = sc.nextInt();
                }

                int asc = arr[1] - arr[0], desc = arr[n - 2] - arr[n - 1];
                asc = asc < 0 ? 0 : asc;
                desc = desc < 0 ? 0 : desc;

                for (int i = 1; i < n - 1; i++) {
                    int tmpAsc = arr[i + 1] - arr[i];
                    int tmpDesc = arr[i] - arr[i + 1];

                    asc = asc > tmpAsc ? asc : tmpAsc < 0 ? 0 : tmpAsc;
                    desc = desc > tmpDesc ? desc : tmpDesc < 0 ? 0 : tmpDesc;
                }

                System.out.println("#" + tc + " " + asc + " " + desc);
            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
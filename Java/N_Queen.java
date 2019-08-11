import java.util.Scanner;

public class N_Queen {

    static int ans, n;

    public static void func(boolean[][] visit, int curY, int curX) {
        if (cury == n) {
            // ans update
            return;
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new FileInputStream("input.txt"))) {
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                n = sc.nextInt();

                boolean[][] visit = new boolean[n][n];

                for(int i = 0; i<n; i++){
                    func(visit,0,i);
                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
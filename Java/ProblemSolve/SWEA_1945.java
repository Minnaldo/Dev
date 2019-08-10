import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class SWEA_1945 {

    static StringBuilder sb = new StringBuilder();

    public static void recur(int n, int a, int b, int c, int d, int e) {
        if (n == 0) {
            sb.append(a + " " + b + " " + c + " " + d + " " + e + " ");
            return;
        }

        recur(n - 2, a + 1, b, c, d, e);
        recur(n - 3, a, b + 1, c, d, e);
        recur(n - 5, a, b, c + 1, d, e);
        recur(n - 7, a, b, c, d + 1, e);
        recur(n - 11, a, b, c, d, e + 1);
    }

    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream("input.txt");
            BufferedReader br = new BufferedReader(new InputStreamReader(fis));

            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {

                int n = Integer.parseInt(br.readLine());

                recur(n, 0, 0, 0, 0, 0);

                System.out.println("#" + tc + " " + sb);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
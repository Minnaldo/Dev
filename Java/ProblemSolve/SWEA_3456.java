import java.io.*;
import java.util.StringTokenizer;

public class SWEA_3456 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {

                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                int tmp = a == b ? c : (a == c ? b : a);

                System.out.println("#" + tc + " " + tmp);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
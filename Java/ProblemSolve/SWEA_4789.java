import java.io.*;

public class SWEA_4789 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                StringBuilder sb = new StringBuilder(br.readLine());
                int size = sb.length();
                int tmpSum = Character.digit(sb.charAt(0), 10);

                for (int i = 1; i < size; i++) {
                    int tmp = Character.digit(sb.charAt(i), 10);
                    if (tmpSum < i) {
                        ans++;
                        tmpSum += 1;
                    } else
                        tmpSum += tmp;
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
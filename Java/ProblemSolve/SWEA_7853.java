import java.io.*;
import java.util.*;

public class SWEA_7853 {

    static HashSet<String> set;

    static void recur(StringBuilder sb, int idx) {
        if (sb.length() == idx) {
            set.add(sb.toString());
            return;
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                set = new HashSet<>();
                StringBuilder sb = new StringBuilder(br.readLine());
                set.add(sb.toString());

                char ori = sb.charAt(0);
                sb.setCharAt(0, sb.charAt(1));
                set.add(sb.toString());
                sb.setCharAt(0, ori);

                ori = sb.charAt(sb.length() - 1);
                sb.setCharAt(sb.length() - 1, sb.charAt(sb.length() - 2));
                set.add(sb.toString());
                sb.setCharAt(sb.length() - 1, ori);

                for (int i = 1; i < sb.length() - 1; i++) {
                    char origin = sb.charAt(i);
                    sb.setCharAt(i, sb.charAt(i - 1));
                    set.add(sb.toString());
                    sb.setCharAt(i, sb.charAt(i + 1));
                    set.add(sb.toString());
                    sb.setCharAt(i, origin);
                }

                System.out.println("#" + tc + " " + set.size());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
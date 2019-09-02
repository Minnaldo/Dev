import java.io.*;
import java.util.HashSet;

/**
 *  반복 패턴의 갯수를 찾으면 된다
 */

public class SWEA_4371 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int n = Integer.parseInt(br.readLine());
                HashSet<Integer> set = new HashSet<>();
                int[] arr = new int[n];

                for (int i = 0; i < n; i++) {
                    arr[i] = Integer.parseInt(br.readLine());
                }

                for (int i = 1; i < n; i++) {
                    set.add(arr[i] - arr[i - 1]);
                }

                System.out.println("#" + tc + " " + set.size());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
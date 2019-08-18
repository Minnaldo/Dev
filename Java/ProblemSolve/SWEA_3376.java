import java.io.*;
import java.util.ArrayList;

public class SWEA_3376 {
    static ArrayList<Long> arr = new ArrayList<>();

    public static void main(String[] args) {
        arr.add(0l);
        arr.add(1l);
        arr.add(1l);
        arr.add(1l);
        arr.add(2l);
        arr.add(2l);

        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                long ans = 0;
                int n = Integer.parseInt(br.readLine());
                // 4번째 전의 값과 현재값을 더하면 된다

                if (n > arr.size() - 1) {
                    while (arr.size() - 1 < n) {
                        arr.add(arr.get(arr.size() - 1) + arr.get(arr.size() - 5));
                    }
                }
                ans = arr.get(n);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
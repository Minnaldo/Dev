import java.io.*;
import java.util.Arrays;

public class Baek_2309 {

    static int[] ans;

    static void combination(int[] arr, int n, int[] sel, int idx) {
        if (idx == sel.length) {
            int sum = 0;
            for (int i = 0; i < sel.length; i++) {
                sum += sel[i];
            }

            if (sum == 100) {
                System.arraycopy(sel, 0, ans, 0, sel.length);
            }
            return;
        }

        if (n == arr.length) {
            return;
        }

        sel[idx] = arr[n];
        combination(arr, n + 1, sel, idx + 1);
        combination(arr, n + 1, sel, idx);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int[] arr = new int[9];
            for (int i = 0; i < 9; i++) {
                arr[i] = Integer.parseInt(br.readLine());
            }
            ans = new int[7];
            // 100이 되는 조합을 찾고 이를 오름차순으로 정렬해 출력하면 된다.
            combination(arr, 0, new int[7], 0);

            Arrays.sort(ans);
            for (int i = 0; i < 7; i++) {
                System.out.println(ans[i]);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
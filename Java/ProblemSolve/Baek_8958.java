import java.io.*;
import java.util.Arrays;

public class Baek_8958 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int n = Integer.parseInt(br.readLine());
            for (int tc = 0; tc < n; tc++) {
                String str = br.readLine();
                int[] arr = new int[str.length() + 1];
                for (int i = 1; i <= str.length(); i++) {
                    if (str.charAt(i - 1) == 'O') {
                        arr[i] = arr[i - 1] + 1;
                    } else {
                        arr[i] = 0;
                    }
                }
                int ans = 0;
                for (int i = 1; i <= str.length(); i++) {
                    ans += arr[i];
                }
                System.out.println(ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
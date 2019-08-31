import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baek_3985 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {

            StringTokenizer st;
            int l = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());
            int[] roll = new int[l + 1];
            int[] manArr = new int[n + 1];
            int[] expect = new int[n + 1];
            int man = 0;
            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int tmp = b - a;
                expect[i] = tmp;
                if (expect[man] < tmp) {
                    man = i;
                }

                for (int j = a; j <= b; j++) {
                    if (roll[j] == 0)
                        roll[j] = i;
                }
            }

            for (int i = 1; i <= l; i++) {
                manArr[roll[i]]++;
            }

            int ans = 1;
            for (int i = 1; i < manArr.length; i++) {
                int tmp = manArr[ans];
                int tmp2 = manArr[i];
                if (tmp < tmp2) {
                    ans = i;
                }
            }

            System.out.println(man);
            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
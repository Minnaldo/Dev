import java.io.*;
import java.util.*;

public class SWEA_1860 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                String ans = "Possible";
                int[] arr = new int[11112];
                StringTokenizer st = new StringTokenizer(br.readLine());
                // n명
                int n = Integer.parseInt(st.nextToken());
                // m초
                int m = Integer.parseInt(st.nextToken());
                // k개
                int k = Integer.parseInt(st.nextToken());

                // m초안에 k명의 이하의 사람이 들어오면 가능
                // m초안에 k명 초과의 사람이 들어오면 불가능
                // 0~n-1까지 이를 판단한다
                st = new StringTokenizer(br.readLine());

                for (int i = 0; i < n; i++) {
                    int tmp = Integer.parseInt(st.nextToken());
                    arr[tmp]++;
                }


                int bread = 0;
                int mCnt = 0;
                for (int i = 0; i <= 11111; i++) {
                    if (i % m == 0 && i != 0) {
                        bread += k;
                    }
                    bread -= arr[i];

                    if (bread < 0) {
                        ans = "Impossible";
                    }
                    mCnt += arr[i];
                    if (mCnt == n) {
                        break;
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
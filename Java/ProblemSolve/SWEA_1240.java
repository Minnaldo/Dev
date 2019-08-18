import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SWEA_1240 {

    static int ans;

    // 코드를 검증한다
    static void check(ArrayList<Integer> arr) {

        int odd = 0, even = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (i % 2 == 0) {
                // 홀수 번째 요소
                odd += arr.get(i);
            } else {
                // 짝수 번째 요소
                even += arr.get(i);
            }
        }
        int ret = (odd * 3) + even + arr.get(arr.size() - 1);

        if (ret % 10 == 0) {
            for (int i = 0; i < arr.size(); i++) {
                ans += arr.get(i);
            }
        } else {
            ans = 0;
        }

    }

    static void func(String str) {
        // 가로 총 56칸
        int start = 0, end = 7;
        ArrayList<Integer> aa = new ArrayList<>();
        while (end <= 56) {

            String tmp = str.substring(start, end);
            int sum = 0;
            for (int i = 0; i < tmp.length(); i++) {
                int tmpBin = Character.digit(tmp.charAt(i), 10) * (int) Math.pow(2, 7 - i - 1);
                sum += tmpBin;
            }

            switch (sum) {
            case 13:
                aa.add(0);
                break;
            case 25:
                aa.add(1);
                break;
            case 19:
                aa.add(2);
                break;
            case 61:
                aa.add(3);
                break;
            case 35:
                aa.add(4);
                break;
            case 49:
                aa.add(5);
                break;
            case 47:
                aa.add(6);
                break;
            case 59:
                aa.add(7);
                break;
            case 55:
                aa.add(8);
                break;
            case 11:
                aa.add(9);
                break;
            }

            start += 7;
            end += 7;
        }
        check(aa);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ans = 0;
                StringTokenizer st = new StringTokenizer(br.readLine());

                int n = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());

                char[][] map = new char[n][m];
                for (int i = 0; i < n; i++) {
                    map[i] = br.readLine().toCharArray();
                }

                // 암호코드인 부분을 찾는다
                int cnt = 0;
                String str = "";
                for (int j = m - 1; j >= 0; j--) { // 79 ~ 0
                    boolean flag = false;
                    for (int i = 0; i < n; i++) {
                        if (map[i][j] == '1') {
                            cnt++;
                        } else {
                            if (cnt >= 5 && cnt <= 50) {
                                str = String.copyValueOf(map[i - 1], j - 55, 56);
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag)
                        break;
                }

                func(str);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
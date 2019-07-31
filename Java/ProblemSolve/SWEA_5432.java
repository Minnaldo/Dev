import java.util.Scanner;

public class SWEA_5432 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            String str = sc.next();
            int ans = 0;
            int len = 0; // 막대의 길이

            for (int i = 0; i < str.length() - 1; i++) {
                // 레이저가 떨어질 때 시작됐지만 끝나지 않은 막대기의 갯수만큼 더하기
                // 막대기가 끝나면 한조각 생겨남 => +1
                // 최대 길이가 10만개이므로 최대 n log n 시간안에 끝내야 함

                if (str.charAt(i) == '(') {
                    if (str.charAt(i + 1) != ')') {
                        len++;
                    } else {
                        ans += len;
                    }
                } else {
                    if (str.charAt(i + 1) == ')') {
                        ans += 1;
                        len--;
                    }
                }
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();

    }
}
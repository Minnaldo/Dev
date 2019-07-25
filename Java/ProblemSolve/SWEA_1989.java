import java.util.*;

public class SWEA_1989 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 1;

            String str = sc.next();
            int size = str.length();
            // 중간위치 구하기
            if (size % 2 == 0) {
                // 문자 길이 짝수
                size = size / 2 + 1;
            } else {
                // 문자 길이 홀수
                size /= 2;
            }

            for (int i = 0; i < size; i++) {
                if (str.charAt(i) != str.charAt(str.length() - (i + 1))) {
                    ans = 0;
                    break;
                }
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();

    }
}
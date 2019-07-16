
/**
 *  ① 만약 현재 부분합이 M 이상이거나, 이미 e = N이면 s++

② 그렇지 않다면 e++

③ 현재 부분합이 M과 같으면 결과 ++
[출처] 투 포인터(Two Pointers Algorithm), 슬라이딩 윈도우(Sliding Window)|작성자 라이
 */

import java.util.*;

/**
 * SWEA_7510 상원이의 연속 합
 * (https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWoEzJFa2A4DFARq&categoryId=AWoEzJFa2A4DFARq&categoryType=CODE)
 * * 구간합 (Prefix Sum) 을 이용한 방법
 */

class SWEA_7510 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int ans = 0;
            int[] arr = new int[n + 1];
            // prefix sum 배열 생성
            for (int i = 1; i <= n; i++) {
                arr[i] = arr[i - 1] + i;
            }
            int start = 0, end = 0;
            while (true) {
                int tmp = arr[end] - arr[start];
                if (tmp == n)
                    ans++;

                if (tmp > n) {
                    start++;
                } else if (end == n)
                    break;
                else
                    end++;

            }

            System.out.printf("#%d %d\n", tc, ans);
        }
    }

    // 완전 탐색을 통한 풀이법
    public static void solve2() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int n = sc.nextInt();

            for (int i = 1; i <= n; i++) {
                int sum = 0;

                for (int j = i; sum < n; j++) {
                    sum += j;
                }

                if (sum == n)
                    ans++;
            }

            System.out.println("#" + tc + " " + ans);
        }
    }
}

import java.io.*;
import java.util.*;

/**
 * 배낭문제 메모
 */

public class DP_Knapsack {
    /**
     * 메모이제이션은 일단 재귀함수를 짠다. 그 다음에 재귀함수가 호출될 때 전달해지는 매개변수를 보고 해당 상태를 구분한다 해당 매개변수 상태를
     * 구분할 수 있는 배열, 혹은 해쉬맵을 준비해서 거기다가 상태에 대한 정보를 저장
     */

    static int k, n;
    static int[] weights, values;
    static int[][] memo;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            n = sc.nextInt();
            k = sc.nextInt();
            weights = new int[n];
            values = new int[n];
            memo = new int[n][k + 1];
            for (int i = 0; i < n; i++) {
                weights[i] = sc.nextInt();
                values[i] = sc.nextInt();
            }

            for (int i = 0; i < n; i++) {
                Arrays.fill(memo[i], -1);
            }
            System.out.println("#" + tc + " " + func(0, 0));
        }

    }

    // 검사중인 아이템의 번호, 지금까지 무게, 지금까지 가치
    // 결과를 기저파트에서 구하는게 아닌, 상태 결과의 값을 리턴한다

    // 올라가며 더하면(리턴으로 더하면) 현재 상태에서 최선의 값을 알 수 있다.
    // 각 상태의 최선값을 미리 저장해두고, 이를 이용한다
    // 리턴값을 어떻게 만들건지를 잘 생각해야 한다
    static public int func(int idx, int weight) {
        // 아이템을 다 고른상황 : 더이상 고를게 없으므로, 기본값인 0을 리턴`
        if (idx == n) {
            return 0;
        }
        if (memo[idx][weight] != -1)
            return memo[idx][weight];

        // 담지 못함
        if (weight + weights[idx] > k) {
            memo[idx][weight] = func(idx + 1, weight);
            return memo[idx][weight];
        } else {
            // 고르고 가는 경우에 현재단계의 값을 더해주고 진행
            memo[idx][weight] = Math.max(func(idx + 1, weight), values[idx] + func(idx + 1, weight + weights[idx]));
            return memo[idx][weight];
        }
    }
}
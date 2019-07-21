
/** 최장 부분 증가 수열
 *  증가하는 부분 수열 중, 가장 긴 부분 증가 수열을 찾는 문제
 */

import java.util.*;

class Lis {
    public static int lower_bound(ArrayList<Integer> arr, int front, int rear, int key) {
        int mid;
        while (front < rear) {
            mid = (front + rear) / 2;
            if (arr.get(mid) < key)
                front = mid + 1;
            else
                rear = mid;
        }
        return rear;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            ArrayList<Integer> answer = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            for (int i = 0; i < n; i++) {
                int cur = arr[i];

                if (answer.isEmpty() || answer.get(answer.size() - 1) < cur) {
                    answer.add(cur);
                } else {
                    // idx = 정답 수열에서 현재 값보다 크거나 같은 원소가 나오는 위치를 리턴한다
                    int idx = lower_bound(answer, 0, answer.size(), cur);
                    // answer.get(idx) = cur;
                    answer.set(idx, cur);
                }
            }

            int ans = answer.size();

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
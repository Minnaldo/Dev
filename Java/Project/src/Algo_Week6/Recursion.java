package Algo_Week6;

import java.util.Arrays;

public class Recursion {
    public static void main(String[] args) {
//        recur(10, 0);
        int[] arr = {3, 1, 4, 5, 2};

        powerSet(arr, 0, new boolean[arr.length]);
        // n C r : n = 전체 갯수, r = 뽑아야 하는 갯수
        // 조합 : n개중 r개를 뽑는 경우의 수
        combination(arr, 0, 3, new int[3], 0);
    }

    // sel은 현재까지 뽑은 원소들을 저장할 변수
    // n은 계속 늘어나면서, arr의 n인덱스에 해당하는 원소를 선택해, sel[idx]에 넣을지 선택을 한다
    static void combination(int[] arr, int n, int r, int[] sel, int idx) {
        if (idx == r) {
            // 다 고른 것
            System.out.println(Arrays.toString(sel));
            return;
        }
        if (n == arr.length) {
            // 끝난 것
            return;
        }

        // 현재 단계(n)에 해당하는 원소를 선택한 경우
        // n번째 원소든 선택을 하든 안하든 다음번째 원소를 선택해야하므로 항상 늘려간다.
        sel[idx] = arr[n];
        // n번째에 대해서 sel에 담고 지나가기
        combination(arr, n + 1, r, sel, idx + 1);
        // n번째에 대해서 sel에 안담고 지나가기
        // idx를 늘리지 않아도 덮어씌워지기 때문에 상관 없다
        combination(arr, n + 1, r, sel, idx);
    }

    static void powerSet(int[] arr, int idx, boolean[] visit) {
        if (idx == arr.length) {
            System.out.println(Arrays.toString(arr));
//            for (int i = 0; i < arr.length; i++) {
//                if (visit[i])
//                    System.out.print(arr[i] + " ");
//            }
//            System.out.println();
            return;
        }

        // 부분집합 구하기
//        visit[idx] = true;
//        powerSet(arr, idx + 1, visit);
//        visit[idx] = false;
//        powerSet(arr, idx + 1, visit);

        // 순열 구하기
        for (int i = idx; i < arr.length; i++) {
            swap(arr, i, idx);
            powerSet(arr, idx + 1, visit);
            swap(arr, i, idx);
        }

    }

    public static void swap(int[] arr, int idx, int idx2) {
        int tmp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = tmp;
    }

    // 0~9까지 재귀함수를 이용해 출력
    public static void recur(int n, int idx) {
        // 기저파트 ( 재귀 함수가 종료되는 조건)
        if (idx == n) {
            return;
        }
        System.out.println(idx);

        recur(n, idx + 1);
    }
}


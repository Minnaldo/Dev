package Algo_Week6;

import java.util.Arrays;

public class PermutationwithRepetition {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4};
//        permutation(arr, 0, new int[2]);

//        perm(arr, 0, new int[3], new boolean[4]);
        perm_swap(arr,0,3,new int[3]);
    }

    // swap을 이용해서도 만들 수 있음
    static void perm(int[] arr, int n, int[] result, boolean[] visit) {
        if (n == result.length) {
            System.out.println(Arrays.toString(result));
            return;
        }

        // 재귀 호출을 어떻게 해야 중복순열이 만들어질까?
        for (int i = 0; i < arr.length; i++) {
            if (!visit[i]) {
                visit[i] = true;
                result[n] = arr[i];
                perm(arr, n + 1, result, visit);
                visit[i] = false;
            }
        }
    }

    static void perm_swap(int[] arr, int n, int r, int result[]) {

        if (n == r) {
            // arr 출력 범위를 r로 하면 똑같다.
            System.out.println(Arrays.toString(arr));
            return;
        }

        for (int i = n; i < arr.length; i++) {
            swap(arr, i, n);
            perm_swap(arr, n + 1, r, result);
            swap(arr, i, n);
        }
    }

    public static void swap(int[] arr, int idx, int idx2) {
        int tmp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = tmp;
    }

    // 중복순열
    static void repetition_permutation(int[] arr, int n, int[] result) {
        if (n == result.length) {
            System.out.println(Arrays.toString(result));
            return;
        }

        // 재귀 호출을 어떻게 해야 중복순열이 만들어질까?
        for (int i = 0; i < arr.length; i++) {
            result[n] = arr[i];
            repetition_permutation(arr, n + 1, result);
        }
    }
}

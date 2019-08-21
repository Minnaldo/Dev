package Algo_Week7;

import java.util.Arrays;

// 재귀호출을 이용한 순열 생성
public class Swap_Permutation {

    static void swap(int[] arr, int idx, int idx2) {
        int tmp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = tmp;
    }

    // n : depth
    // n과 r의 위치를 바꾼다
    static void permu(int[] arr, int r) {

        if (r == arr.length) {
            System.out.println(Arrays.toString(arr));
            return;
        }

        // i와 r의 위치를 바꾼다
        for (int i = r; i < arr.length; i++) {
            swap(arr, i, r);
            permu(arr, r + 1);
            swap(arr, i, r);
        }
    }

    public static void main(String[] args) {
        // arr.length개에서 arr개를 찾는 경우의 수
        int[] arr = {1, 2, 3};
        permu(arr, 0);
    }
}

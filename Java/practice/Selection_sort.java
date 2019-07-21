/**
 *  선택 정렬
 *  원래의 배열 안에서 이루어지는 in-place sorting 방법 중 하나
 *  배열 내에서 가장 큰값을 찾아 현재 위치와 바꾼다 (SWAP)
 */

import java.util.*;

public class Selection_sort {

    public static void main(String[] args) {
        int[] arr = { 7, 4, 2, 8, 9, 6, 3, 5, 0, 1 };

        int max = 0;
        int max_idx = 0;
        // arr 배열에서 가장 큰 값을 찾아 max에 저장하고, 그 위치를 max_idx에 저장
        int size = arr.length;

        // 가장 큰 값을 찾아 현재 인덱스와 바꾼다
        // 이를 계속 해나간다
        for (int j = 0; j < size; j++) {
            max = 0;
            for (int i = j; i < size; i++) {
                if (max < arr[i]) {
                    max = arr[i];
                    max_idx = i;
                }
            }
            int tmp = arr[j];
            arr[j] = arr[max_idx];
            arr[max_idx] = tmp;
        }

        System.out.println(Arrays.toString(arr));
    }
}
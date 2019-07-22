
// package practice;

import java.util.*;
import java.io.*;

public class MergeSort {

    static int[] tmp;

    public static void merge(int[] arr, int start, int mid, int end) {
        int left = start;
        int tmpidx = start;
        int right = mid + 1;

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                tmp[tmpidx++] = arr[left++];
            } else
                tmp[tmpidx++] = arr[right++];
        }

        if (left > mid) {
            for (int i = right; i <= end; i++)
                tmp[tmpidx++] = arr[i];
        } else {
            for (int i = left; i <= mid; i++)
                tmp[tmpidx++] = arr[i];
        }

        for (int i = start; i <= end; i++)
            arr[i] = tmp[i];
    }

    public static void divide(int[] arr, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            divide(arr, start, mid);
            divide(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

    public static void merge_sort(int[] arr, int start, int end) {
        divide(arr, start, end);
    }

    public static void main(String[] args) {

        int n = 10;
        int[] arr = { 3, 5, 1, 2, 9, 8, 7, 10, 4, 6 };
        tmp = new int[n];

        System.out.println("============정렬 전============");
        System.out.println(Arrays.toString(arr));

        divide(arr, 0, n - 1);

        System.out.println("============정렬 후============");
        System.out.println(Arrays.toString(arr));

        System.out.println("\n정렬 완료");
    }
}
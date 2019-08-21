import java.util.*;
import java.io.*;

/**
 * @param r : 피봇역할, 기준아이템
 * @param i : r보다 작은값의 가장 오른쪽 인덱스
 * @param j : r보다 큰값의 가장 오른쪽 인덱스
 */

public class Quick_Sort_romuto {

    static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    static int partition(int[] arr, int start, int end) {
        int i = start;

        for (int j = start; j < end; j++) {
            if (arr[j] <= arr[end]) {
                swap(arr, i, j);
                i++;
            }
        }
        swap(arr, i, end);
        return i;
    }

    static int partition2(int[] arr, int start, int end) {
        // 가장 첫번째 값을 피벗으로 지정할 때
        int pivotIdx = start;
        int i = start, j = end;

        while (i < j) {
            while (arr[i] < arr[pivotIdx])
                i++;
            while (arr[j] > arr[pivotIdx] && i < j)
                j--;

            swap(arr, i, j);
        }
        swap(arr, pivotIdx, j);
        return j;
    }

    static void sort(int[] arr) {
        sort(arr, 0, arr.length - 1);
    }

    static void sort(int[] arr, int start, int end) {

        if (start < end) {
            int part = partition2(arr, start, end);
            sort(arr, start, part - 1);
            sort(arr, part + 1, end);
        }
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("sort_input.txt")) {
            Scanner sc = new Scanner(fis);

            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            System.out.println("정렬전");
            System.out.println(Arrays.toString(arr));
            sort(arr);
            System.out.println("정렬후");
            System.out.println(Arrays.toString(arr));

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

public class MergeSort8 {
    private static int[] sorted;

    private static void merge(int[] arr, int start, int mid, int end) {
        int left = start;
        int right = mid + 1;
        int idx = start;

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                sorted[idx++] = arr[left++];
            } else {
                sorted[idx++] = arr[right++];
            }
        }

        if (left > mid) {
            for (int i = right; i <= end; i++) {
                sorted[idx++] = arr[i];
            }
        } else {
            for (int i = left; i <= mid; i++) {
                sorted[idx++] = arr[i];
            }
        } // end of sort

        for (int i = start; i <= end; i++) {
            arr[i] = sorted[i];
        }

    }

    private static void divide(int[] arr, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            divide(arr, start, mid);
            divide(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

    private static void sort(int[] arr) {
        divide(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("merge_intput.txt")) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            sorted = new int[n];
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            System.out.println("================ 정렬 전 ================");
            System.out.println(Arrays.toString(arr));
            sort(arr);
            System.out.println("================ 정렬 후 ================");
            System.out.println(Arrays.toString(arr));

            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
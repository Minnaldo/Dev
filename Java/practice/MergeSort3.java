
/**
 *  MergeSort practice Day 3
 *  병합정렬은 분할-정복(Devide & Conquer) 방식의 정렬 알고리즘이므로, 분할과 정복 과정을 나누어 진행한다
 */

import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class MergeSort3 {

    public static int[] tmp;

    // 부분 배열이 들어오면 이를 정렬해 tmp배열에 임시로 저장하며 정렬을 진행한다.
    public static void merge(int[] arr, int start, int mid, int end) {
        int left = start; // start는 부분배열의 시작 인덱스
        int right = mid + 1; // mids는 부분배열의 중간 인덱스
        int tmpIdx = start; // tmpIdx는 임시 배열의 인덱스

        // while문의 조건은 부분배열의 좌/우 중 한 곳의 정렬이 완료 될 때까지 한다는 뜻
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                tmp[tmpIdx++] = arr[left++];
            } else {
                tmp[tmpIdx++] = arr[right++];
            }
        }

        // 남은 부분을 임시배열에 넣어준다.
        if (left > mid) {
            for (int i = right; i <= end; i++) {
                tmp[tmpIdx++] = arr[i];
            }
        } else {
            for (int i = left; i <= mid; i++) {
                tmp[tmpIdx++] = arr[i];
            }
        }

        // 정렬된 것을 원래 배열에 적용시킨다.
        for (int i = 0; i <= end; i++) {
            arr[i] = tmp[i];
        }
    }

    public static void divide(int[] arr, int start, int end) {
        // start < end 가 성립하지 않을 때 : 부분배열 내의 데이터가 하나만 존재할 때
        if (start < end) {
            int mid = (start + end) / 2;
            // 꼭 첫번째 먼저 해야하나??
            divide(arr, start, mid);
            divide(arr, mid + 1, end);
            // 숫자들의 나열이 분리가 완료되면 정렬을 시작
            merge(arr, start, mid, end);
        }
    }

    public static void main(String[] args) {

        // the data in input.txt : 9 3 5 1 2 4 10 8 6 7
        try (FileInputStream fis = new FileInputStream("sort_input.txt")) {
            Scanner sc = new Scanner(fis);

            int n = sc.nextInt();
            int[] arr = new int[n];
            tmp = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();

            System.out.println("=====정렬 전=====");
            System.out.println(Arrays.toString(arr));
            // start Merge sort
            divide(arr, 0, n - 1);

            System.out.println("=====정렬 후=====");
            System.out.println(Arrays.toString(arr));

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
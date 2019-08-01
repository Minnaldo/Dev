import java.io.*;
import java.util.*;

public class MergeSort6 {

    private static int[] sorted;

    private static void merge(int[] arr, int start, int mid, int end) {
        int left = start;
        int right = mid + 1;
        int idx = start; // 정렬된 요소를 저장해둘 임시 배열의 인덱스

        // 한쪽의 데이터가 정렬이 될 때 까지 임시배열에 저장하며 정렬한다
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                sorted[idx++] = arr[left++];
            } else {
                sorted[idx++] = arr[right++];
            }
        }

        if (left > mid) {
            // 왼쪽 부분배열이 모두 정렬되었을 때
            // 남은 부분을 모두 정렬한다. 남은부분을 모두 임시배열에 넣어준다
            for (int i = right; i <= end; i++) {
                sorted[i] = arr[i];
            }
        } else {
            // 오른쪽 부분 배열이 모두 정렬되었을 때
            // 남은 부분을 모두 정렬한다
            for (int i = left; i <= mid; i++) {
                sorted[i] = arr[i];
            }
        }
        // 실질적인 정렬 완료
        // 임시배열에 정렬되어있는 데이터를 원래 배열에 넣어준다
        // 배열의 인덱스는 start 부터 end이므로, 반복문의 반복 범위도 이와 같이 한다
        for (int i = start; i <= end; i++) {
            arr[i] = sorted[i];
        }

    }

    private static void divide(int[] arr, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            // 들어온 배열을 가장 작아질때까지 나눈다.
            divide(arr, start, mid);
            divide(arr, mid + 1, end);
            // 나눈 후 정복 부분
            merge(arr, start, mid, end);
        }
    }

    private static void sort(int[] arr) {
        // 배열의 인덱스는 0부터 arr.length-1
        divide(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("merge_input.txt")) {
            Scanner sc = new Scanner(fis);
            int n = sc.nextInt();
            int[] arr = new int[n];
            sorted = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            System.out.println("======================정렬 전======================");
            System.out.println(Arrays.toString(arr));

            sort(arr);

            System.out.println("======================정렬 후======================");
            System.out.println(Arrays.toString(arr));

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
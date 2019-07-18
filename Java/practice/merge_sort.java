import java.util.*;

public class merge_sort {

    static int[] tmp;

    public static void merge(int[] arr, int start, int end) {
        if (arr[start] > arr[end]) {
            tmp[start] = arr[end];
            tmp[end] = arr[start];
        } else {
            tmp[start] = arr[start];
            tmp[end] = arr[end];
        }
    }

    public static void divide(int[] arr, int start, int end) {
        // divide, 원소의 갯수가 2개 이상일 때
        if (start < end) {
            int mid = (start + end) / 2;
            divide(arr, start, mid);
            divide(arr, mid + 1, end);
        }

        // 원소의 갯수가 2개 이하이면 정렬을 한다.
        merge(arr, start, end);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // 배열의 원소 갯수
        int[] arr = new int[n];
        tmp = new int[n];

        divide(arr, 0, n - 1);

        sc.close();
    }
}
import java.util.Arrays;

public class quick_sort {

    private static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    private static void quicksort(int[] arr) {
        quicksort(arr, 0, arr.length - 1);
    }

    private static void quicksort(int[] arr, int start, int end) {
        if (start < end) {
            int part = partition(arr, start, end);
            partition(arr, start, part - 1);
            partition(arr, part, end);
        }
    }

    private static int partition(int[] arr, int start, int end) {
        // 배열의 중간에 있는 값을 피벗으로 설정
        int pivot = arr[(start + end) / 2];

        while (start <= end) {
            while (arr[start] < pivot)
                start++;
            while (arr[end] > pivot)
                end++;
            if (start <= end) {
                swap(arr, start, end);
                start++;
                end--;
            }
        }

        return start;
    }

    public static void main(String[] args) {
        int[] arr = { 2, 0, 1, 6, 8, 5, 6, 3, 4, 9, 7 };
        System.out.println("==================================정렬 전==================================");
        System.out.println(Arrays.toString(arr));
        quicksort(arr);
        System.out.println("==================================정렬 전==================================");
        System.out.println(Arrays.toString(arr));

    }
}
import java.util.Arrays;

public class bubble_sort2 {

    public static void swap(int[] arr, int idx, int idx2) {
        int tmp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = tmp;
    }

    public static void main(String[] args) {
        int[] arr = { 7, 5, 6, 3, 4, 1, 2 };
        int size = arr.length;

        System.out.println("===============정렬 전===============");
        System.out.println(Arrays.toString(arr));
        System.out.println();

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                // 오름차순 정렬의 조건
                if (arr[j] >= arr[j + 1]) {
                    swap(arr, j, j + 1);
                }
            }
        }

        System.out.println("===============정렬 후===============");
        System.out.println(Arrays.toString(arr));
    }
}
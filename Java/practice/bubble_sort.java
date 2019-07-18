import java.util.*;

public class bubble_sort {

    public static void swap(int[] arr, int idx, int idx2) {
        int tmp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = tmp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int size = arr.length;

        for(int i = 0; i<size; i++)
            arr[i] = sc.nextInt();

        for (int j = 0; j < size; j++)
            for (int i = 0; i < size - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    // swap
                    swap(arr, i, i+1);
                }
            }


        System.out.println(Arrays.toString(arr));
        sc.close();
    }
}
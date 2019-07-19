import java.util.*;
import java.io.*;

public class Merge_Sort_2 {

    // 단순 임시배열에 불과하므로, sorted 배열을 그대로 썻다가는 문제가 생길 수 있다.
    static int[] sorted;

    // merge 함수는 배열이 나뉘는 구간만큼 실행이 된다
    // 즉, 매번 구간을 나타내는 변수인 start, mid, end 변수가 다르게 들어올 것이며
    // 이는 merge함수 매 실행 시 마다 원래의 배열에 덮어써주어야 한다는 뜻이 된다.
    public static void merge(int[] arr, int start, int mid, int end) {
        int left = start;
        int right = mid + 1;
        int sortIdx = start;

        // 나뉘어진 배열 끼리 비교해 정렬한다
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                sorted[sortIdx++] = arr[left++];
            } else {
                sorted[sortIdx++] = arr[right++];
            }
        }

        // 남은 부분을 정렬해준다
        if (right > end) {
            for (int i = left; i <= mid; i++) {
                sorted[sortIdx++] = arr[i];
            }
        } else {
            for (int i = right; i <= end; i++) {
                sorted[sortIdx++] = arr[i];
            }
        }

        // 정렬된 배열을 넣어준다
        for (int i = 0; i < arr.length; i++)
            arr[i] = sorted[i];
    }

    public static void divide(int[] arr, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            divide(arr, start, mid);
            divide(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);

            int n = sc.nextInt();
            sorted = new int[n];
            int[] arr = new int[n];
            System.out.println("정렬 전 : " + Arrays.toString(arr));

            divide(arr, 0, n);

            System.out.println("정렬 후 : " + Arrays.toString(sorted));

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
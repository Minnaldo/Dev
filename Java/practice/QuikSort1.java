import java.util.Scanner;

// quick sort day 1
// 재귀 방식을 이용해 코드를 작성한다.
// 불안정 정렬 방식중 하나
// 피벗을 기준으로 좌/우로 정렬을 진행한다.
// 피벗 선정 방식에 따라 처리 속도가 달라질 수 있다.

// TODO

public class QuikSort1 {

    private static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    private static int partition(int[] arr, int start, int end) {
        // 가장 왼쪽값을 피벗으로 잡는다.
        int pivot = arr[start];
        int left = start, right = end;

        while (left < right) {
            while (pivot < arr[right]) {
                right--;
            }

            while (left < right && pivot >= arr[left]) {
                left++;
            }
            swap(arr, left, right);
        }

        arr[start] = arr[left];
        arr[left] = pivot;
        return left;
    }

    private static void sort(int[] arr, int start, int end) {
        if (start >= end)
            return;

        // 피벗이 된다
        int pivot = partition(arr, start, end);

        sort(arr, start, pivot - 1);
        sort(arr, pivot - 1, end);
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("sort_input.txt")) {
            Scanner sc = new Scanner(System.in);

            // 원소의 갯수
            int n = sc.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            System.out.println("====================================정렬 전====================================");
            System.out.println(Arrays.toString(arr));

            sort(arr);

            System.out.println("====================================정렬 후====================================");
            System.out.println(Arrays.toString(arr));

            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.util.*;

public class Merge_Sort {

    // 임시로 정렬된 값들을 저장할 배열
    static int[] tmp;

    public static void merge(int[] arr, int start, int mid, int end) {

        int left = start;
        int right = mid + 1;
        int tmpIdx = start;

        // 분할된 배열들 일부 정렬
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right])
                tmp[tmpIdx++] = arr[left++];
            else
                tmp[tmpIdx++] = arr[right++];
        }

        // 남아있는 배열들 마저 정렬, 왼쪽 부분 배열 부터 정렬 후 오른쪽 부분배열 정렬
        // if문을 한번만 쓰는 이유 : 윗단계에서 왼쪽 부분배열이나 오른쪽 부분배열 둘중 하나가 끝나야만 while문이 끝나기 때문이다.
        if (left < mid) {
            // 왼쪽 부분 배열에 값이 남아있는 경우
            for (int i = left; i <= mid; i++) {
                tmp[tmpIdx++] = arr[i];
            }
        } else {
            // 오른쪽 부분 배열에 값이 남아있는 경우
            for (int i = right; i <= end; i++) {
                tmp[tmpIdx++] = arr[i];
            }
        }

    } // 병합 완료

    public static void divide(int[] arr, int start, int end) {
        // divide, 원소의 갯수가 2개 이상일 때
        if (start < end) {
            int mid = (start + end) / 2;
            divide(arr, start, mid);
            divide(arr, mid + 1, end);
            merge(arr, start, mid, end); // 분할된 배열을 병합한다.
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // 배열의 원소 갯수
        int[] arr = new int[n];
        tmp = new int[n];

        divide(arr, 0, n - 1);

        // 정렬된 값들을 출력한다.
        System.out.println(Arrays.toString(tmp));

        sc.close();
    }
}
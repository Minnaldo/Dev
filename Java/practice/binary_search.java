import java.util.*;
import java.io.*;

/**
 * 2진 탐색 분할-정복 기법 중 하나 계속 2분할 해가며 해를 찾는다.
 */

public class binary_search {

    public static int search(int[] arr, int key) {

        int left = 0;
        int right = arr.length - 1;
        int mid = 0;
        // binary search start
        // 병합정렬에서는 최소 2개를 남겨야 하기에 조건이 left < right
        while (left <= right) {
            mid = (left + right) / 2;

            if (arr[mid] < key) {
                left = mid + 1;
            } else if (arr[mid] > key) {
                right = mid - 1;
            } else {
                right = mid;
                break;
            }
        }
        System.out.println(arr[right]);
        return right;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt(); // 데이터 갯수 입력
        // int[] arr = new int[n];
        // for (int i = 0; i < n; i++) {
        // arr[i] = sc.nextInt();
        // }

        int[] arr = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169 };

        // 찾고자 하는 값 입력
        System.out.println("찾고자 하는 값을 입력 해 주세요");
        System.out.println("찾는값의 위치는 " + (search(arr, sc.nextInt()) + 1) + "번 째 입니다.");

        sc.close();
    }
}
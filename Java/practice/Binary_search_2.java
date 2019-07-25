import java.util.*;

/**
 *  D5는 최적화를 요하는 문제, 완전탐색으로는 힘들다
 */

public class Binary_search_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169 };

        int left = 0;
        int right = arr.length - 1;
        int mid = 0;

        int key = sc.nextInt();
        while (left <= right) {

            mid = (left + right) / 2;

            if (arr[mid] > key) {
                right = mid - 1;
            } else if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid;
                break;
            }
        }

        if (right > 0) {
            System.out.println(key + "보다 작은 제곱수는 " + arr[right]+"이고,");
            System.out.println(mid + 1 + "번 째 에서 찾았습니다");
        }
    }
}
import java.util.*;
import java.io.*;

/**
 * 2진 탐색 분할-정복 기법 중 하나 계속 2분할 해가며 해를 찾는다.
 */

public class binary_search {

    public static int search(int[] arr, int key, int start, int end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else {
            if (mid < key) {
                search(arr, key, start, mid - 1);
            } else {
                search(arr, key, mid + 1, end);
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 데이터 갯수 입력
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // 찾고자 하는 값 입력
        int key = sc.nextInt();
        int ans = 0;
        if((ans = search(arr, key, start, arr.length-1)) == -1){
            System.out.println("찾는값이 없습니다.");
        }
        else{
            System.out.println("찾는값의 자표는 "+ans+"번 째 입니다.");
        }

        sc.close();
    }
}
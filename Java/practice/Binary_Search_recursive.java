import java.util.*;

public class Binary_Search_recursive {

    public static void search(int[] arr, int key, int left, int right) {
        if (left > right) {
            return;
        }

        int mid = (left + right) / 2;

        if (key == arr[mid]) {
            System.out.println("위치는 : " + mid);
            return;
        } else if (key < arr[mid]) {
            search(arr, key, left, mid - 1);
        } else if (key > arr[mid]) {
            search(arr, key, mid + 1, right);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int[] arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        int key = sc.nextInt();
        search(arr, key, 0, arr.length - 1);
        sc.close();
    }
}
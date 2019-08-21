import java.util.*;

public class Bottle_cap_game {
    public static void main(String[] args) {
        int[] arr = { 1, 3, 5, 7, 9, 11, 13, 15 };

        int low = 0;
        int high = arr.length - 1;

        int key = new Scanner(System.in).nextInt();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key) {
                high = mid;
                break;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        System.out.println(high);
    }
}
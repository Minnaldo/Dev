import java.util.Arrays;
import java.util.Scanner;

public class Baek_1244 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }

        int sNum = sc.nextInt();
        int bulb = 0;
        // 남학생 1, 여학생 2
        for (int i = 0; i < sNum; i++) {
            switch (sc.nextInt()) {
            case 1:
                // 남학생
                bulb = sc.nextInt();
                for (int j = bulb; j <= n; j += bulb) {
                    arr[j] = arr[j] == 1 ? 0 : 1;
                }
                break;
            case 2:
                // 여학생
                bulb = sc.nextInt();
                int left = bulb;
                int right = bulb;
                while (left >= 1 && right <= n) {
                    if (arr[left] == arr[right]) {
                        arr[left] = arr[left] == 1 ? 0 : 1;
                        arr[right] = arr[left];
                        left--;
                        right++;
                    } else {
                        break;
                    }
                    // if (arr[left] != arr[right] || (left == 0 || right >= n)) {
                    // left++;
                    // right--;
                    // for (int a = left; a <= right; a++) {
                    // arr[a] = arr[a] == 1 ? 0 : 1;
                    // }
                    // break;
                    // } else if (arr[left] == arr[right]) {
                    // left--;
                    // right++;
                    // }
                }
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " ");
            if (i % 20 == 0) {
                System.out.println();
            }
        }
        // System.out.print(arr[n]);

        sc.close();
    }
}
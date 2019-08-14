import java.util.Scanner;

// ? 0이되면 안되지 않나?

public class SWEA_1486 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int b = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            int min = 987654321;
            for (int i = 0; i < (1 << n); i++) {
                int tmpSum = 0;
                for (int j = 0; j < n; j++) {
                    if (((1 << j) & i) != 0) {
                        tmpSum += arr[j];
                    }
                }

                if (tmpSum >= b) {
                    min = min < tmpSum ? min : tmpSum;
                }
            }
            System.out.println("#" + tc + " " + (min - b));
        }
        sc.close();
    }
}
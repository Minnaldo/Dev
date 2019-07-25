import java.util.Scanner;

/**
 * 가운데 있는 노드가 최상위 루트노드
 */

public class SWEA_7985 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int k = sc.nextInt();
            int node = (int) (Math.pow(2, k)) - 1;
            int[] arr = new int[node];

            // init
            for (int i = 0; i < node; i++) {
                arr[i] = sc.nextInt();
            }

            int idx = node / 2;

            System.out.println("#" + tc + " \n" + arr[idx]);

            for (int i = k - 1; i > 0; i--) {
                String tmp = "";
                idx /= 2;
                for (int j = idx; j <= node; j += Math.pow(2, i)) {
                    tmp += arr[j] + " ";
                }

                tmp.trim();
                System.out.println(tmp);
            }
        }
        sc.close();
    }
}
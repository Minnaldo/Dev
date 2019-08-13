
/** TODO
 *  ! 메모리 초과
 */

import java.util.*;

public class Baek_6603 {

    static HashSet<String> permu = new HashSet<>();

    public static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    public static void perm(int[] arr, int depth, int n, int r) {
        // 6개의 수를 뽑는다
        if (depth == r) {
            // print
            int[] tmp = new int[r];
            System.arraycopy(arr, 0, tmp, 0, r);
            Arrays.sort(tmp);
            String str = "";
            for (int val : tmp) {
                str += val + " ";
            }
            permu.add(str.trim());
            return;
        }

        for (int i = 0; i < n; i++) {
            swap(arr, i, depth);
            perm(arr, depth + 1, n, r);
            swap(arr, i, depth);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int k = 0;
        while (true) {
            k = sc.nextInt();
            if (k == 0) {
                return;
            }
            int[] arr = new int[k];
            for (int i = 0; i < k; i++) {
                arr[i] = sc.nextInt();
            }

            // 6개를 고르는 조합
            perm(arr, 0, k, 6);
            ArrayList<String> finans = new ArrayList<>(permu);
            Collections.sort(finans);

            for (String val : finans) {
                System.out.println(val);
            }
            System.out.println();
        }
    }
}
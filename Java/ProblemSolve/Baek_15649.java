import java.util.*;

/** N 과 M
 *  * 1부터 N까지의 자연수 중에서 중복 없이 M개를 고른 수열
 *  * nPm (Permutation; 순열) 을 구하는 문제
 *  * 순열은 결과 리스트에서 중복을 허용하지 않으므로, visit함수를 이용해 리스트에 넣었는지 체크를 한다
 */

public class Baek_15649 {

    static int[] arr;
    static ArrayList<String> ans;
    static HashSet<String> set;

    static void perm(int[] sel, int n, int k, boolean[] visit) {
        if (k == sel.length) {
            StringBuilder sb = new StringBuilder();

            for (int val : sel) {
                sb.append(val).append(" ");
            }
            set.add(sb.toString().trim());
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                sel[k] = arr[i];
                perm(sel, n, k + 1, visit);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        arr = new int[n];
        set = new HashSet<>();
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        perm(new int[m], n, 0, new boolean[n]);

        ans = new ArrayList<>(set);

        Collections.sort(ans);

        for (int i = 0; i < ans.size(); i++) {
            System.out.println(ans.get(i));
        }
    }
}
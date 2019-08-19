
/** TODO
 *  ! 메모리 초과
 */

import java.io.*;
import java.util.*;

public class Baek_6603 {

    static HashSet<String> permu = new HashSet<>();

    static void combi(int[] arr, int n, int[] sel, int idx) {
        // 기저사례
        if (idx == sel.length) {
            Arrays.sort(sel);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < sel.length - 1; i++) {
                sb.append(sel[i]).append(" ");
            }
            sb.append(sel[sel.length - 1]);
            permu.add(sb.toString());
            return;
        }
        if (n == arr.length) {
            return;
        }

        sel[idx] = arr[n];
        combi(arr, n + 1, sel, idx + 1);
        combi(arr, n + 1, sel, idx);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int k = 0;
            while (true) {
                // k = sc.nextInt();
                StringTokenizer st = new StringTokenizer(br.readLine());
                k = Integer.parseInt(st.nextToken());
                if (k == 0) {
                    return;
                }
                int[] arr = new int[k];
                for (int i = 0; i < k; i++) {
                    arr[i] = Integer.parseInt(st.nextToken());
                }

                // 6개를 고르는 조합
                // perm(arr, 0, k, 6);
                combi(arr, 0, new int[6], 0);
                ArrayList<String> finans = new ArrayList<>(permu);
                Collections.sort(finans, new Comparator<String>() {
                    @Override
                    public int compare(String o1, String o2) {
                        o1 = o1.replaceAll(" ", "");
                        o2 = o2.replaceAll(" ", "");

                        for (int i = 0; i < o1.length(); i++) {
                            if (o1.charAt(i) - o2.charAt(i) < 0) {
                                return -1;
                            } else if (o1.charAt(i) - o2.charAt(i) > 0) {
                                return 1;
                            }
                        }
                        return 0;
                    }
                });

                for (String val : finans) {
                    System.out.println(val);
                }
                System.out.println();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
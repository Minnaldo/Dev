import java.io.*;
import java.util.*;

/**
 * 새샘이의 7-3-5 게임
 */

public class SWEA_5948 {

    static TreeSet<Integer> ansSet;

    static void combi(ArrayList<Integer> arr, int[] sel, int n, int idx) {
        if (idx == sel.length) {
            int sum = 0;
            for (int val : sel) {
                sum += val;
            }
            ansSet.add(sum);
            return;
        }
        if (n == arr.size()) {
            return;
        }

        sel[idx] = arr.get(n);
        combi(arr, sel, n + 1, idx + 1);
        combi(arr, sel, n + 1, idx);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ansSet = new TreeSet<>();
                String str = br.readLine();
                StringTokenizer st = new StringTokenizer(str);
                ArrayList<Integer> aa = new ArrayList<>();
                while (st.hasMoreTokens()) {
                    aa.add(Integer.parseInt(st.nextToken()));
                }
                combi(aa, new int[3], 0, 0);
                ArrayList<Integer> ansList = new ArrayList<>(ansSet);
                int ans = ansList.get(ansList.size() - 5);
                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
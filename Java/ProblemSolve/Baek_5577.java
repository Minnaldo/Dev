import java.io.*;
import java.util.*;

/**
 * * 남아있는 공의 최소 갯수를 구하는 문제 * 지우는걸 어떻게 진행하게 할것인가> *
 */

public class Baek_5577 {

    static int ans, n;

    // dfs를 이용해 같은 문자열의 길이를 탐색한다
    static int dfs(ArrayList<Integer> arr, int cnt, int idx) {
        if (arr.get(idx) != arr.get(idx + 1)) {
            return cnt;
        }
        return dfs(arr, cnt + 1, idx + 1);
    }

    static void func(ArrayList<Integer> arr, boolean[] visit) {
        int i = 0;
        while (i < arr.size() - 3) {
            int cnt = 0;
            // if (arr.get(i) == arr.get(i + 1))
            // cnt = dfs(arr, 0, i);

            for (int a = i; i < arr.size() - 1; a++) {
                if (arr.get(a) == arr.get(a + 1)) {
                    cnt++;
                } else {
                    break;
                }
            }

            if (cnt + 1 > 3) {
                // System.out.println("i=" + i);
                for (int j = i; j < i + cnt; j++) {
                    System.out.println("j=" + j);
                    arr.remove(j);
                }
                i = 0;
            } else {
                i++;
            }
            System.out.println(arr.toString());
        }

        int fin = arr.size();
        ans = ans < fin ? ans : fin;
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            n = Integer.parseInt(br.readLine());
            ans = 987654321;
            ArrayList<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                arr.add(Integer.parseInt(br.readLine()));
            }

            for (int i = 5; i < 6; i++) {
                int initVal = arr.get(i);
                if (initVal == 1) {
                    arr.set(i, 2);
                    func(new ArrayList<>(arr), new boolean[n]);
                    arr.set(i, 3);
                    func(new ArrayList<>(arr), new boolean[n]);
                } else if (initVal == 2) {
                    arr.set(i, 1);
                    func(new ArrayList<>(arr), new boolean[n]);
                    arr.set(i, 3);
                    func(new ArrayList<>(arr), new boolean[n]);
                } else {
                    arr.set(i, 1);
                    func(new ArrayList<>(arr), new boolean[n]);
                    arr.set(i, 2);
                    func(new ArrayList<>(arr), new boolean[n]);
                }
                arr.set(i, initVal);
            }

            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
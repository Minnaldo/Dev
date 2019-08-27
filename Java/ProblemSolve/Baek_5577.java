import java.io.*;
import java.util.*;

/**
 * * 남아있는 공의 최소 갯수를 구하는 문제 * 지우는걸 어떻게 진행하게 할것인가> *
 */

public class Baek_5577 {

    static int ans, n;

    static void func(ArrayList<Integer> arr, boolean[] visit) {
        int i = 0;

        while (i < arr.size() - 3) {
            int cnt = 0;
            for (int a = i; i < arr.size() - 1; a++) {
                if (arr.get(a) == arr.get(a + 1)) {
                    cnt++;
                } else {
                    break;
                }
            }
            // 왜 안지워 지는 겨 ?
            if (cnt + 1 > 3) {
                int rmIdx = i;
                for (int j = i; j <= i + cnt; j++) {
                    arr.remove(rmIdx);
                }
                i = 0;
            } else {
                i++;
            }
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

            for (int i = 0; i < n; i++) {
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
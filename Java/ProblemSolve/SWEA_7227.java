import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SWEA_7227 {

    static void combi(Pair[] arr, int n, int r, Pair[] sel, int idx) {
        if (r == idx) {
            for (int i = 0; i < sel.length; i++) {
                System.out.println(sel[i].first + "    " + sel[i].second);
            }
            System.out.println();
            return;
        }
        if (n == arr.length) {
            return;
        }

        sel[idx] = arr[n];
        combi(arr, n + 1, r, sel, idx + 1);
        combi(arr, n + 1, r, sel, idx);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                int n = Integer.parseInt(br.readLine());
                Pair[] arr = new Pair[n];
                for (int i = 0; i < n; i++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    arr[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                }

                // 지렁이들 짝의 조합을 구한다
                combi(arr, 0, 2, new Pair[2], 0);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1101&sca=50&sfl=wr_subject&stx=%EB%83%89%EC%9E%A5%EA%B3%A0&sop=and
 */

public class Jung_1828 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            Pair[] arr = new Pair[n];
            StringTokenizer st;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                arr[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }
            Arrays.sort(arr, new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    return o1.second - o2.second;
                }
            });

            int ans = 0;
            int end = -987654321;
            for (Pair p : arr) {
                if (p.first > end) {
                    ans++;
                    end = p.second;
                }
            }

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
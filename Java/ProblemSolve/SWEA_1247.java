import java.io.*;
import java.util.StringTokenizer;

/**
 * * 순열을 이용하여 가능한 모든 경로를 찾은 다음
 * * 거리를 계산하여 최단거리를 찾는다
 */

public class SWEA_1247 {

    static int ans;
    static Pair me, house;

    static void getDist(Pair[] sel) {
        int tmp = Math.abs(me.y - sel[0].y) + Math.abs(me.x - sel[0].x);
        for (int i = 0; i < sel.length - 1; i++) {
            tmp += Math.abs(sel[i].y - sel[i + 1].y) + Math.abs(sel[i].x - sel[i + 1].x);
        }

        tmp += Math.abs(sel[sel.length - 1].y - house.y) + Math.abs(sel[sel.length - 1].x - house.x);
        ans = ans < tmp ? ans : tmp;
    }

    static void recur(Pair[] arr, Pair[] sel, int idx, boolean[] visit) {
        if (idx == sel.length) {
            // for (Pair p : sel) {
            // System.out.println(p.x + " " + p.y);
            // }
            getDist(sel);
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (!visit[i]) {
                sel[idx] = arr[i];
                visit[i] = true;
                recur(arr, sel, idx + 1, visit);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());

            for (int tc = 1; tc <= t; tc++) {
                ans = 987654321;
                int n = Integer.parseInt(br.readLine());
                StringTokenizer st = new StringTokenizer(br.readLine());

                Pair[] customer = new Pair[n];
                me = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                house = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

                for (int i = 0; i < n; i++) {
                    customer[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                }

                recur(customer, new Pair[n], 0, new boolean[n]);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int y, x;

        Pair(int x, int y) {
            this.y = y;
            this.x = x;
        }
    }
}
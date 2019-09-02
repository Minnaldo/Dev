import java.io.*;
import java.util.*;

public class Baek_5567 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int n = Integer.parseInt(br.readLine());
            int m = Integer.parseInt(br.readLine());
            boolean[] visit = new boolean[n + 1];
            visit[1] = true;
            int[][] arr = new int[n + 1][2];
            for (int i = 0; i < m; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 2; j++)
                    arr[i][j] = Integer.parseInt(st.nextToken());
            }

            Queue<Pair> q = new LinkedList<>();
            q.add(new Pair(1, 1));

            while (!q.isEmpty()) {
                int cur = q.peek().first;
                int depth = q.peek().depth;

                for (int i = 0; i < arr.length; i++) {
                    if (arr[i][0] == cur ) {
                        q.add(arr[i][1]);
                    }
                }
            }

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (visit[i])
                    ans++;
            }
            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, depth;

        Pair(int first, int depth) {
            this.first = first;
            this.depth = depth;
        }
    }
}
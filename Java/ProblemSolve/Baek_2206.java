import java.io.*;
import java.util.*;

public class Baek_2206 {

    static int n, m, ans, len;
    static int[][] map, dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        ans = 987654321;
        map = new int[n][m];
        boolean[][] visit = new boolean[n][m];
        // init
        for (int i = 0; i < n; i++) {
            char[] tmp = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                map[i][j] = Character.digit(tmp[j], 10);
            }
        }
        visit[0][0] = true;
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, true));

        ans = ans == 987654321 ? -1 : ans;
        System.out.println(ans);
    }

    static class Node {
        int y, x;
        boolean through;

        Node(int y, int x, boolean through) {
            this.y = y;
            this.x = x;
            this.through = through;
        }
    }
}
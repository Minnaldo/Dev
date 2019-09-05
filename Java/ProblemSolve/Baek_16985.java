import java.io.*;
import java.util.*;

/**
 * Maaaaaaaaaze
 *
 */

public class Baek_16985 {

    static int ans;
    static int[][] dir = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, -1, 0 }, { 0, 0, -1 } }; // z y x

    static void dfs(int x, int y, int ex, int ey, int depth, int cnt, Plate[] maze) {

        Queue<Node> q = new LinkedList<>();
        q.add(new Node(depth, y, x, 1));

        while (!q.isEmpty()) {
            Node node = q.poll();

            for (int i = 0; i < 6; i++) {
                int nz = node.z + dir[i][0];
                int ny = node.y + dir[i][1];
                int nx = node.x + dir[i][2];

                if (nz == 4 && ny == ey && nx == ex) {
                    ans = Math.min(ans, node.cnt);
                    return;
                }

                if (nz < 0 || ny < 0 || nx < 0 || nz >= 5 || ny >= 5 || nx >= 5)
                    continue;
                if (!maze[nz].visit[ny][nx] && maze[nz].map[ny][nx] == 1) {
                    maze[nz].visit[ny][nx] = true;
                    q.add(new Node(nz, ny, nx, node.cnt + 1));
                }
            }
        }
    }

    // 시계 방향으로 90도 회전
    static int[][] rotate(int[][] map) {
        int[][] tmp = new int[5][5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tmp[j][4 - i] = map[i][j];
            }
        }
        return tmp;
    }

    // plate들을 합치는 기능
    // 각 판마다 회전 후 넘어가기
    static void combine(Plate[] maze, int idx) {

        if (idx == 5) {
            find(maze);
            return;
        }

        for (int i = 0; i < 4; i++) {
            maze[idx].map = rotate(maze[idx].map);
            combine(maze, idx + 1);
        }
    }

    // 만들어진 정육면체를 탐색
    // 6면을 탐색해서 길이있으면 지나가면서 카운트 증가
    // 출구와 입구의 갯수는 각 8개씩 이나, 입구-> 출구 가 길이 있다면 출구 -> 입구도 길이 있는 것이므로 4번만 하면 된다
    static void find(Plate[] maze) {
        dfs(0, 0, 4, 4, 0, 1, maze);
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {

            Plate[] maze = new Plate[5];
            // input
            for (int i = 0; i < 5; i++) {
                int[][] tmp = new int[5][5];
                for (int j = 0; j < 5; j++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    for (int k = 0; k < 5; k++) {
                        tmp[j][k] = Integer.parseInt(st.nextToken());
                    }
                }
                maze[i] = new Plate(tmp);
            }

            ans = 987654321;
            combine(maze, 0);
            // 탐색이 불가능 할 때
            ans = ans == 987654321 ? -1 : ans;
            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Plate {
        int[][] map;
        boolean[][] visit;

        Plate(int[][] map) {
            this.map = map;
            this.visit = new boolean[5][5];
        }
    }

    static class Node {
        int z, y, x, cnt;

        Node(int z, int y, int x, int cnt) {
            this.z = z;
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    }
}
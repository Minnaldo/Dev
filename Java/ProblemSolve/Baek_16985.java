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

        if (depth == 4 && x == ex && y == ey) {
            ans = Math.min(ans, cnt);
            return;
        }

        for (int i = 0; i < 6; i++) {
            int nd = depth + dir[i][0];
            int ny = y + dir[i][1];
            int nx = x + dir[i][2];
            // 범위 내 일때
            if (nd >= 0 && ny >= 0 && nx >= 0 && nd < 5 && nx < 5 && ny < 5) {
                if (!maze[nd].visit[ny][nx] && maze[nd].map[ny][nx] == 1) {
                    maze[nd].visit[ny][nx] = true;
                    dfs(nx, ny, ex, ey, nd, cnt + 1, maze);
                    maze[nd].visit[ny][nx] = false;
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
}
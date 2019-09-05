import java.util.*;
import java.io.*;

/**
 * * ans가 12가 되면, 최소이므로 이후에는 찾을 필요가 없으니 끝내버린다
 */

public class Maaaaaaaaaze {
    static int[][][] map = new int[5][5][5];
    static int ans = 987654321;
    static int[][] dir = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, -1, 0 }, { 0, 0, -1 } };

    // height층의 행열을 90도 회전시키는 함수.
    static void rotate(int height) {
        int[][] tmp = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tmp[j][4 - i] = map[height][i][j];
            }
        }

        // 돌린 배열을 원본 배열에 복사
        map[height] = tmp;
    }

    // 모든 회전 조합을 만드는 상태트리 재귀 함수
    // 몇층을 작업하는지만 알면 된다
    static void dfs(int h_idx) {
        if (h_idx == 5) {
            // 마지막 층까지 다 셋팅 완료 120가지의 모든 층 변경을 따져볼 차례
            // 회전이 끝난후 순열함수를 호출하면
            // 순열의 기저파트에서는 해당 회전 조합에 대해서 모든 경우의 수에 층 배열이 떨어짐
            perm(0);
            return;
        }

        for (int i = 0; i < 4; i++) {
            // 돌리고 다음칸
            rotate(h_idx);
            dfs(h_idx + 1);
        }
    }

    static void bfs() {
        boolean[][][] visit = new boolean[5][5][5];
        Queue<Node> q = new LinkedList<>();

        q.add(new Node(0, 0, 0, 1));
        visit[0][0][0] = true;

        while (!q.isEmpty()) {
            Node node = q.poll();

            for (int i = 0; i < 6; i++) {
                int nz = node.z + dir[i][0];
                int ny = node.y + dir[i][1];
                int nx = node.x + dir[i][2];

                if (nz == 4 && ny == 4 && nx == 4) {
                    ans = Math.min(ans, node.cnt);
                    return;
                }

                if (nz < 0 || ny < 0 || nx < 0 || nz >= 5 || ny >= 5 || nx >= 5)
                    continue;
                if (!visit[nz][ny][nx] && map[nz][ny][nx] == 1) {
                    visit[nz][ny][nx] = true;
                    q.add(new Node(nz, ny, nx, node.cnt + 1));
                }
            }
        }

    }

    static void perm(int idx) {
        // 기저영역
        if (idx == 5) {
            // 길찾기
            // NOTE ans != 12 : 5*5*5 크기의 정육면체에서 가장 짧은 길이의 길은 길이가 12일 것이다. 그러므로 이미 정답변수가 12가
            // 되었다면 탐색을 하지 않도록 하여 시간을 줄인다
            // 출발지점과 도착지점에 들어갈 수 있어야 의미있으므로, 들어갈 수 있는 지 확인 후 들어간다
            if (map[0][0][0] == 1 && map[4][4][4] == 1 && ans != 12)
                bfs();
            return;
        }

        // 실질적으로는 swap함수에서 바뀜
        for (int i = idx; i < 5; i++) {
            swap(i, idx);
            perm(idx + 1);
            swap(i, idx);
        }
    }

    // 순열 함수 (스왑)
    // 3차원 배열에 대해서 각 층을 바꾸는 코드
    static void swap(int a, int b) {
        int[][] tmp = map[a];
        map[a] = map[b];
        map[b] = tmp;
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            // input
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    for (int k = 0; k < 5; k++) {
                        map[i][j][k] = Integer.parseInt(st.nextToken());
                    }
                }
            }

            dfs(0);
            // 탐색이 불가능 할 때
            ans = ans == 987654321 ? -1 : ans;
            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
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
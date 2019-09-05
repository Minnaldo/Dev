import java.io.*;
import java.util.*;

// 남은 벽돌의 갯수가 가장 작아야 한다

public class SWEA_BreakBlock {

    static int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    static int n, w, h, ans;

    static void dfs(int[][] map, int cnt) {
        if (cnt == n) {
            // 시행이 끝났을때 최소로 남는 경우의 벽돌 갯수를 구한다
            int block = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (map[i][j] > 0)
                        block++;
                }
            }
            // 최솟값 갱신
            ans = Math.min(ans, block);
            return;
        }

        for (int i = 0; i < w; i++) {
            // i 위치에 떨어트려 터트리고, 지운다
            drop(map, i);
            // 다음번 시행을 한다
            dfs(map, cnt + 1);
        }
    }

    // idx위치에 공을 떨어트리는 경우
    static void drop(int[][] map, int idx) {
        int rmNum = 0;
        int top = 0;
        for (int i = 0; i < h; i++) {
            if (map[i][idx] > 0) {
                rmNum = map[i][idx];
                top = i;
                map[i][idx] = 0;
                break;
            }
        }

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(top, idx, rmNum));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            for (int k = 0; k < p.mul; k++) {
                for (int i = 0; i < 4; i++) {
                    int ny = p.first + dir[i][0] * k;
                    int nx = p.second + dir[i][1] * k;

                    if (ny >= 0 && nx >= 0 && ny < h && nx < w) {
                        q.add(new Pair(ny, nx, map[ny][nx]));
                        map[ny][nx] = 0;
                    }
                }
            }
        }
        // 모두 터트린후 블록 내리기
        down(map);
    }

    static void down(int[][] map) {
        // 블록들을 내린다
        for (int i = 0; i < w; i++) {
            for (int j = h - 1; j >= 0; j--) {
                int idx = 0;
                if (map[j][i] == 0) {
                    for (int a = j; a >= 0; a--) {
                        if (map[a][i] != 0) {
                            idx = a;
                            break;
                        }
                    }
                    map[j][i] = map[idx][i];
                    map[idx][i] = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ans = 987654321;

                StringTokenizer st = new StringTokenizer(br.readLine());
                n = Integer.parseInt(st.nextToken());
                w = Integer.parseInt(st.nextToken());
                h = Integer.parseInt(st.nextToken());

                int[][] map = new int[h][w];
                for (int i = 0; i < h; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < w; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                    }
                }

                dfs(map, 0);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second, mul;

        Pair(int first, int second, int mul) {
            this.first = first;
            this.second = second;
            this.mul = mul;
        }
    }
}
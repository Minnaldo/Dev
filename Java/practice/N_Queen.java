import java.util.*;

public class N_Queen {

    static int[][] dir = { { -1, -1 }, { -1, 0 }, { -1, 1 } };
    static int N, ans;

    static void backtrack(int[][] map, int idx) {
        // 모든 행을 다 검사하였음
        if (idx == map.length) {
            ans++;
            return;
        }

        // 해당 열의 갯수만큼 반복하며 해당 열에 퀸을 배치하고 다음 행 재귀 호출
        for (int i = 0; i < map[idx].length; i++) {
            // 가지치기 (Prunning) : 될성 싶으면
            // idx, i
            int cnt = 0;
            loop: for (int k = 0; k < 3; k++) {
                for (int mul = 1; mul <= N; mul++) {
                    int ny = idx + dir[k][0] * mul;
                    int nx = i + dir[k][1] * mul;
                    if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
                        if (map[ny][nx] == 1) {
                            cnt++;
                            break loop;
                        }
                    }
                }
            }
            if (/* prunning */cnt == 0) {
                map[idx][i] = 1;
                backtrack(map, idx + 1);
                map[idx][i] = 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            ans = 0;
            N = sc.nextInt(); // 체스판의 크기이자 퀸의 수
            backtrack(new int[N][N], 0);
            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
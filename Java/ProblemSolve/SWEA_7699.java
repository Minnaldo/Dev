import java.io.*;
import java.util.StringTokenizer;

/**
 *  수지의 수지맞는 여행
 *  * DFS로 풀어도 되지만, 순열 구할때의 개념을 이용하는 것도 좋은 방법이다.
 *  * 방문하지 않은 다음 위치를 들어가기전, 방문 체크 배열에 체크를 하고
 *  * 돌아오면 방문 체크 했던 위치를 체크 해제 한다
 *  * 이는 재귀를 통해 순열을 구하는 문제와 유사하다
 */

public class SWEA_7699 {

    static int ans, r, c;
    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    static void recur(char[][] map, boolean[] visit, int y, int x, int cnt) {

        boolean flag = false;
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
                if (!visit[map[ny][nx] - 'A']) {
                    visit[map[ny][nx] - 'A'] = true;
                    recur(map, visit, ny, nx, cnt + 1);
                    visit[map[ny][nx] - 'A'] = false;
                    flag = true;
                }
            }
        }

        if (!flag)
            ans = ans > cnt ? ans : cnt;
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                ans = 0;

                StringTokenizer st = new StringTokenizer(br.readLine());
                r = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());

                char[][] map = new char[r][c];
                for (int i = 0; i < r; i++) {
                    map[i] = br.readLine().toCharArray();
                }

                boolean[] visit = new boolean[26];
                visit[map[0][0] - 'A'] = true;
                recur(map, visit, 0, 0, 1);

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
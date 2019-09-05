import java.io.*;
import java.util.*;

public class Baek_4179 {

    static String ans;
    static int[][] dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    static Jihun jihun;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int jy = 0, jx = 0;
            int fy = 0, fx = 0;
            char[][] map = new char[r][c];
            boolean[][] visit = new boolean[r][c];
            for (int i = 0; i < r; i++) {
                char[] tmp = br.readLine().toCharArray();
                for (int j = 0; j < c; j++) {
                    map[i][j] = tmp[j];
                    if (tmp[j] == 'J') {
                        jy = i;
                        jx = j;
                    } else if (tmp[j] == 'F') {
                        fy = i;
                        fx = j;
                        visit[i][j] = true;
                    }
                }
            }

            Queue<Pair> fq = new LinkedList<>();
            Queue<Jihun> jq = new LinkedList<>();
            jq.add(new Jihun(jy, jx, 1));
            fq.add(new Pair(fy, fx));
            loop: while (true) {
                // 종료 조건
                // 지훈이가 불을 만나거나, 탈출하는 경우

                // 불 확산
                Pair p = fq.poll();
                for (int i = 0; i < 4; i++) {
                    int nfy = p.first + dir[i][0];
                    int nfx = p.second + dir[i][1];

                    if (nfy >= 0 && nfx >= 0 && nfy < r && nfx < c) {
                        if (map[nfy][nfx] == '.') {
                            visit[nfy][nfx] = true;
                            map[nfy][nfx] = 'F';
                            fq.add(new Pair(nfy, nfx));
                        }
                    }
                }

                // 지훈이 이동
                int tmp = 0;
                while (!jq.isEmpty()) {
                    tmp = 0;
                    Jihun j = jq.poll();
                    for (int i = 0; i < 4; i++) {
                        int ny = j.first + dir[i][0];
                        int nx = j.second + dir[i][1];
                        tmp++;
                        if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
                            if (!visit[ny][nx] && map[ny][nx] == '.') {
                                jq.add(new Jihun(ny, nx, j.cnt + 1));
                            }
                        } else {
                            ans = "" + j.cnt;
                            break loop;
                        }
                    }

                }
                if (tmp == 4) {
                    ans = "IMPOSSIBLE";
                    break loop;
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

    static class Jihun {
        int first, second, cnt;

        Jihun(int first, int second, int cnt) {
            this.first = first;
            this.second = second;
            this.cnt = cnt;
        }
    }
}
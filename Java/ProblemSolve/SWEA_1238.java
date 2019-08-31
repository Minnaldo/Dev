import java.io.*;
import java.util.*;
/**
 * * 인접 행렬을 만들어서 bfs를 이용한다
 */

public class SWEA_1238 {

    static boolean[] visit;
    static int[][] map;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            for (int tc = 1; tc <= 10; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int start = Integer.parseInt(st.nextToken());
                int ans = 0;
                map = new int[101][101];
                visit = new boolean[101];
                st = new StringTokenizer(br.readLine());

                for (int i = 0; i < (n / 2); i++) {
                    int y = Integer.parseInt(st.nextToken());
                    int x = Integer.parseInt(st.nextToken());
                    // y에서 x로 가는길이 있으면 1
                    map[y][x] = 1;
                }

                Queue<Integer> q = new LinkedList<>();
                q.add(start);
                visit[start] = true;
                HashMap<Integer, Integer> hmap = new HashMap<>();
                hmap.put(start, 1);
                while (!q.isEmpty()) {
                    int current = q.poll();
                    // 우선은 100까지 돌자
                    for (int i = 1; i <= 100; i++) {
                        if (map[current][i] == 1) {
                            if (!visit[i]) {
                                // 연락할 수 있고
                                // 연락을 한적이 없을 때
                                q.add(i);
                                hmap.put(i, hmap.get(current) + 1);
                                visit[i] = true;
                            }
                        }
                    }
                }

                int max = 0;
                for (Integer key : hmap.keySet()) {
                    int seq = hmap.get(key);
                    max = max > seq ? max : seq;
                }

                for (Integer key : hmap.keySet()) {
                    if (hmap.get(key) == max) {
                        ans = ans > key ? ans : key;
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
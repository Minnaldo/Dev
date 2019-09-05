import java.io.*;
import java.util.*;

public class Baek_16236 {

    static int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } }, map;
    static int ans, n;
    static Shark shark;

    static void solution(int y, int x, int cnt) {
        int fSum = 0;
        ArrayList<Pair> arr = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                fSum += map[ny][nx];
                if (map[ny][nx] > 0) {
                    arr.add(new Pair(ny, nx));
                }
            }
        }

        if (fSum == 0) {
            // call mother
            ans = cnt;
            return;
        } else if (arr.size() == 1) {
            shark.bodySize += fSum;
            shark.first = arr.get(0).first;
            shark.second = arr.get(0).second;
        } else {
            // 가장 가까운 물고기를 찾는다
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            ans = 0;
            n = Integer.parseInt(br.readLine());

            map = new int[n][n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if (map[i][j] == 9) {
                        shark.first = i;
                        shark.second = j;
                        shark.bodySize = 2;
                    }
                }
            }

            solution(shark.first, shark.second, 0);

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    static class Shark {
        int bodySize, first, second;

        Shark(int first, int second, int bodySize) {
            this.first = first;
            this.second = second;
            this.bodySize = bodySize;
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
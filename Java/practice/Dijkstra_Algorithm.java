import java.io.*;
import java.util.*;

public class Dijkstra_Algorithm {
    static int[] dist; // 최단거리를 기록할 배열
    static boolean[] visit; // 방문한 정점을 저장할 배열
    static int inf = 987654321;
    static int[][] map;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int start = sc.nextInt();

        dist = new int[n + 1];
        visit = new boolean[n + 1];
        map = new int[n + 1][n + 1];

        for (int i = 0; i <= n; i++) {
            dist[i] = inf;
        }

        for (int i = 0; i < m; i++) {
            map[sc.nextInt()][sc.nextInt()] = sc.nextInt();
        }

        // 첫 코드에서 무슨잘못을 했을까?
        // 시작점에서 갈수있는 곳을 체크한다
        for (int i = 1; i <= n; i++) {
            if (map[start][i] > 0) {
                dist[i] = map[start][i];
            }
        }
        visit[start] = true;

        // n -1 개의 정점을 선택해가며 최단거리를 갱신
        for (int i = 1; i <= n; i++) {
            // dist배열 중에서 가장 값이 작은 정점을 찾기
            // dist배열에서 최솟값의 인덱스
            int minIdx = 0;
            // dist배열에서 최솟값
            int min = 987654321;
            for (int j = 1; j <= n; j++) {
                if (!visit[j] && min > dist[j]) {
                    minIdx = j;
                    min = dist[j];
                }
            }

            // 모든 정점에 대해서 시작점에서 min위치를 들러서 다른 정점으로 가는 거리가 기존에 알던 dist보다 작으면 갱신
            for (int j = 1; j <= n; j++) {
                // min에서 검사하는 정점으로 갈 수 있는지 여부 map[minIdx][j] != 0
                // 검사하는 정점까지 알고 있던 거리 dist[j]
                if (map[minIdx][j] != 0) {
                    dist[j] = Math.min(dist[minIdx] + map[minIdx][j], dist[j]);
                }
            }
            visit[minIdx] = true;
        }
        System.out.println(Arrays.toString(dist));
    }
}
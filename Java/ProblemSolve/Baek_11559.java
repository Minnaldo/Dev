import java.io.*;
import java.util.*;

/**
 *  Baek_11559 : Puyo Puyo (https://www.acmicpc.net/problem/11559)
 *
 */

public class Baek_11559 {

    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    static int ans;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            char[][] map = new char[12][6];

            for (int i = 0; i < 12; i++) {
                map[i] = br.readLine().toCharArray();
            }

            // 내리는 거 - 임시배열을 만들어, 하나씩 읽어가며 붙여넣는다 -- 이후 원래배열로 치환
            // 없애는 거 - 연속된 같은색의 블록이 있으면 모두 없앤다 -- BFS?
            // 카운팅 하는 것 - 뭉쳐진 하나의 블록을 없앨때마다 1 증가
            ans = 0;
            remove(map, new boolean[12][6]);

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 내리는 거 - Down
    static char[][] down(char[][] map) {
        char[][] tmp = new char[12][6];
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                tmp[i][j] = '.';
            }
        }

        for (int j = 0; j < 6; j++) {
            // tmp에는 idx,j에 map[i][j] 값을 집어 넣는다
            int idx = 11; // tmp의 위치를 나타낼 인덱스
            for (int i = 11; i >= 0; i--) {
                if (map[i][j] != '.') {
                    tmp[idx--][j] = map[i][j];
                    map[i][j] = '.';
                }
            }
        }
        // 밑으로 정렬한 맵을 리턴한다
        return tmp;
    }

    // 삭제를 하려면
    // 삭제할 수 있는지 확인을 해야한다. --1
    // 삭제 후 생겨난 배열을 파라미터로 하는 down함수를 불러 정렬한다. --2
    // 1~2 를 더이상 삭제할 것이 없을 때 까지 반복한다
    static void remove(char[][] map, boolean[][] visit) {
        // 삭제할 수 있는지 확인하려면 -- BFS를 통해 몇개가 뭉쳐 있는지 확인 후, 4개 이상이라면 삭제를 진행한다.
        // 방문 배열을 통해 방문을 확인 한 후, 이를 이용하여 삭제를 진행
        // 삭제는 .으로 바꾸면 되겠다

        ArrayList<Pair> aaa = new ArrayList<>();

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && !visit[i][j]) {
                    // 여기서부터 bfs 시작
                    char chk = map[i][j];
                    Queue<Pair> q = new LinkedList<>();
                    ArrayList<Pair> arr = new ArrayList<>();
                    q.add(new Pair(i, j));
                    arr.add(new Pair(i, j));
                    visit[i][j] = true;

                    while (!q.isEmpty()) {
                        int y = q.peek().first;
                        int x = q.peek().second;

                        for (int a = 0; a < 4; a++) {
                            int ny = y + dir[a][0];
                            int nx = x + dir[a][1];

                            if (ny >= 0 && nx >= 0 && ny < 12 && nx < 6) {
                                if (!visit[ny][nx] && map[ny][nx] == chk) {
                                    arr.add(new Pair(ny, nx));
                                    q.add(new Pair(ny, nx));
                                    visit[ny][nx] = true;
                                }
                            }
                        }
                        q.poll();
                    }
                    if (arr.size() >= 4) {
                        aaa.addAll(arr);
                    }
                }
            }
        }
        // 지우기
        if (aaa.size() > 0) {
            for (int i = 0; i < aaa.size(); i++) {
                map[aaa.get(i).first][aaa.get(i).second] = '.';
            }
            map = down(map);
            ans++;
            remove(map, new boolean[12][6]);
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
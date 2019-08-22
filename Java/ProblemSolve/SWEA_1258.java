import java.io.*;
import java.util.*;

public class SWEA_1258 {

    static ArrayList<Pair> arr;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int n = Integer.parseInt(br.readLine());
                arr = new ArrayList<>();
                int[][] map = new int[n][n];
                boolean[][] visit = new boolean[n][n];
                // input
                for (int i = 0; i < n; i++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < n; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                    }
                }

                // logic start
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (!visit[i][j] && map[i][j] != 0) {
                            int row = i, col = j, col2 = j;
                            int cnt = 0, cnt2 = 0;
                            while (map[row][col++] != 0) {
                                cnt++;
                            }
                            while (map[row++][col2] != 0) {
                                cnt2++;
                            }
                            // 행, 열, 사이즈
                            arr.add(new Pair(cnt, cnt2, cnt * cnt2));

                            // 방문 체크
                            for (int a = i; a < row; a++)
                                for (int b = j; b < col; b++)
                                    visit[a][b] = true;
                        }
                    }
                }

                // size순 정렬
                // size가 같으면 second 순으로 정렬
                // 그 다음 first
                Collections.sort(arr, new Comparator<Pair>() {

                    @Override
                    public int compare(Pair p1, Pair p2) {
                        if (p1.size < p2.size) {
                            return -1;
                        } else if (p1.size == p2.size) {
                            if (p1.second < p2.second) {
                                return -1;
                            }
                        }
                        return 1;
                    }
                });
                StringBuilder sb = new StringBuilder();
                sb.append(arr.size() + " ");
                for (int i = 0; i < arr.size(); i++) {
                    sb.append(arr.get(i).second + " " + arr.get(i).first).append(" ");
                }

                bw.write("#" + tc + " ");
                bw.write(sb.toString().trim() + "\n");
                bw.flush();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second;
        int size;

        Pair(int first, int second, int size) {
            this.first = first;
            this.second = second;
            this.size = size;
        }
    }
}
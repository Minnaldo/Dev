import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class SWEA_1210 {

    static ArrayList<Integer> arr;
    static int n = 100, ans;
    static StringTokenizer st;

    static void solution(int[][] map, int y, int x, int arIdx) {
        for (int i = y; i >= 0; i--) {
            if (x - 1 >= 0 && map[i][x - 1] == 1) {
                x = arr.get(--arIdx);
            } else if (x + 1 < n && map[i][x + 1] == 1) {
                x = arr.get(++arIdx);
            }
            // System.out.println(x);
        }

        ans = x;
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            BufferedReader br = new BufferedReader(new InputStreamReader(fis));

            for (int tc = 1; tc <= 10; tc++) {
                ans = 0;
                int t = Integer.parseInt(br.readLine());
                int[][] map = new int[n][n];

                int gx = 0;
                for (int i = 0; i < n; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < n; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                        if (map[i][j] == 2) {
                            gx = j;
                        }
                    }
                }

                arr = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    if (map[0][i] == 1) {
                        arr.add(i);
                    }
                }
                solution(map, 99, gx, arr.indexOf(gx));

                System.out.println("#" + tc + " " + ans);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
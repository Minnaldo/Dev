import java.io.*;
import java.util.*;

public class SWEA_3282_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            Things[] arr = new Things[n + 1];
            arr[0] = new Things(0, 0);
            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine());
                arr[i] = new Things(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }

            Arrays.sort(arr, new Comparator<Things>() {

                @Override
                public int compare(Things o1, Things o2) {
                    return Integer.compare(o1.weight, o2.weight);
                }
            });

            int[][] map = new int[n + 1][k + 1];

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= k; j++) {
                    if (j - arr[i].weight >= 0) {
                        map[i][j] = Math.max(map[i - 1][j], arr[i].value + map[i - 1][j - arr[i].weight]);
                    } else {
                        map[i][j] = Math.max(map[i][j], map[i - 1][j]);
                    }
                }
            }

            System.out.println("#" + tc + " " + map[n][k]);
        }
    }

    static class Things {
        int weight, value;

        Things(int weight, int value) {
            this.weight = weight;
            this.value = value;
        }
    }
}
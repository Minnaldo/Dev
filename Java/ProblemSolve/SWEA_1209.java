import java.io.*;
import java.util.StringTokenizer;

public class SWEA_1209 {
    static int[][] map = new int[100][100];

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            for (int tc = 1; tc <= 10; tc++) {
                int t = Integer.parseInt(br.readLine());
                int ans = 0;
                int[] arr = new int[100];
                for (int i = 0; i < 100; i++) {
                    StringTokenizer st = new StringTokenizer(br.readLine());
                    int tmpSum = 0;
                    for (int j = 0; j < 100; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                        tmpSum += map[i][j];
                        arr[j] += map[i][j];
                    }
                    ans = ans > tmpSum ? ans : tmpSum;
                }

                int left = 0, right = 0;
                for (int i = 0; i < 100; i++) {
                    int ny = 0 + (1 * i);
                    int nx = 0 + (1 * i);
                    int ny1 = 0 + (1 * i);
                    int nx1 = 99 + (-1 * i);

                    left += map[ny][nx];
                    right += map[ny1][nx1];

                    ans = ans > arr[i] ? ans : arr[i];
                }

                ans = ans > left ? ans : left;
                ans = ans > right ? ans : right;

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
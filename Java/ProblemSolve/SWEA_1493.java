import java.util.*;

public class SWEA_1493 {
    static int[][] map = new int[500][500];

    public static void make_map() {
        int cnt = 1;
        int y = 1, x = 1;
        int xidx = 1;
        while (cnt <= 50000) {
            map[y][x] = cnt++;
            if (x == 1) {
                y = 1;
                x = ++xidx;
            } else {
                y++;
                x--;
            }
        }
    }

    // 10000 + 10000이 나올 수 있다
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        make_map();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            int p = sc.nextInt();
            int q = sc.nextInt();

            int px = 0, py = 0, qx = 0, qy = 0;
            // 각 수의 좌표 구하기
            for (int i = 1; i < 142; i++) {
                for (int j = 1; j < 142; j++) {
                    if (map[i][j] == p) {
                        py = i;
                        px = j;
                    }
                    if (map[i][j] == q) {
                        qy = i;
                        qx = j;
                    }
                }
            }

            ans = map[py + qy][px + qx];
            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
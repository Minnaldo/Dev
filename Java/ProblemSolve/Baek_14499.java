import java.io.*;
import java.util.StringTokenizer;
import java.util.Vector;

public class Baek_14499 {
    static int[][] dir = { { 0, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } }, map;
    static int n, m, k;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            map = new int[n][m];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            Vector<Integer> arr = new Vector<>();
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                int oper = Integer.parseInt(st.nextToken());

                int ny = y + dir[oper][0];
                int nx = x + dir[oper][1];

                // 바깥으로 나가는 명령이니 무시
                if (ny < 0 && nx < 0 && ny >= n && nx >= m)
                    continue;

                // 주사위를 굴린 후, 바닥면의 값과, 맵의 값을 비교
                int under = 10; // 바닥면의 값 (임시)
                if(map[ny][nx] == 0 ){
                    map[ny][nx] = under;
                }else{
                    // 칸의 값을 주사위에 복사
                    under = map[ny][nx];
                }

                arr.add(top);

            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Dice {
        int[] num = { 2, 3, 5, 4 }, num2 = { 6, 3, 1, 4 }, num3 = { 2, 6, 5, 1 }, num4 = { 2, 1, 5, 6 },
                num5 = { 1, 3, 6, 4 }, num6 = { 5, 3, 2, 4 };
        int under = 1;

        Dice(int under) {
            this.under = under;
        }
    }
}
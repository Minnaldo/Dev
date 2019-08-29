import java.io.*;
import java.util.*;

// TODO

public class Baek_5212 {

    static int[][] dir = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            char[][] map = new char[r + 2][c + 2];

            for (int i = 1; i <= r; i++) {
                char[] tmp = br.readLine().toCharArray();
                int idx = 0;
                for (int j = 1; j <= c; j++) {
                    map[i][j] = tmp[idx++];
                }
            }

            ArrayList<Pair> arr = new ArrayList<>();
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (map[i][j] == 'X') {
                        int cnt = 0;
                        for (int k = 0; k < 4; k++) {
                            int ny = i + dir[k][0];
                            int nx = j + dir[k][1];

                            if (map[ny][nx] == '.') {
                                cnt++;
                            }
                        }
                        if (cnt > 2)
                            arr.add(new Pair(i, j));
                    }
                }
            }

            for (int i = 0; i < arr.size(); i++) {
                Pair p = arr.get(i);
                map[p.first][p.second] = '.';
            }

            ArrayList<Integer> yy = new ArrayList<>();
            ArrayList<Integer> xx = new ArrayList<>();
            for (int i = 0; i <= r + 1; i++) {
                int size = map[i].length;
                boolean flag = true;
                for (int j = 0; j < size; j++) {
                    if (map[i][j] == 'X') {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    yy.add(i);
                }
            }

            for (int i = 0; i <= c + 1; i++) {
                int size = r + 2;
                boolean flag = true;
                for (int j = 0; j < size; j++) {
                    if (map[i][j] == 'X') {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    xx.add(i);
                }
            }

            for(int i = 0; i<yy.size(); i++){
                int idx = yy.get(i);
            }
            for(int i = 0; i<xx.size(); i++){

            }

        } catch (Exception e) {
            e.printStackTrace();
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
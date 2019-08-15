import java.util.*;
import java.io.*;

//TODO

public class SWEA_1249 {

    static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int ans = 987654321;
                int n = sc.nextInt();
                int[][] map = new int[n][n];
                int[][] visit = new int[n][n];
                boolean[][] chk = new boolean[n][n];

                for (int i = 0; i < n; i++) {
                    char[] ch = sc.next().toCharArray();
                    for (int j = 0; j < ch.length; j++) {
                        map[i][j] = Character.digit(ch[j], 10);
                        // visit[i][j] = 98765321;
                    }
                }

                // Queue<Pair> q = new LinkedList<>();
                // q.add(new Pair(0, 0));

                // while (!q.isEmpty()) {
                // int y = q.peek().first;
                // int x = q.peek().second;

                // for (int i = 0; i < 4; i++) {
                // int ny = y + dir[i][0];
                // int nx = x + dir[i][1];
                // if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
                // // 아예 안할 수 있는 케이스도 존재 할 듯

                // int sum = visit[y][x] + map[ny][nx];
                // if (visit[ny][nx] != 0) {
                // visit[ny][nx] = visit[ny][nx] < sum ? visit[ny][nx] : sum;
                // } else {
                // visit[ny][nx] = sum;
                // }
                // chk[y][x] = true;
                // }
                // }
                // q.poll();
                // }

                // ans = visit[n - 1][n - 2] < visit[n - 2][n - 1] ? visit[n - 1][n - 2] :
                // visit[n - 2][n - 1];


                for (int[] aa : visit) {
                    for (int val : aa) {
                        System.out.print(val);
                    }
                    System.out.println();
                }
                ans = visit[n - 1][n - 1];
                System.out.println("#" + tc + " " + ans);
            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
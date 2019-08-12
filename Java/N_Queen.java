import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.*;

public class N_Queen {

    static int ans, n;
    static int[][] dir = { { 1, -1 }, { 1, 0 }, { 1, 1 } };

    public static void func(boolean[][] visit, int curY, int curX) {
        if (curY + 1 == n) {
            // ans update
            ans++;
            System.out.println("증가");
            return;
        }

        System.out.println("=========방문 전========");
        printer(visit);
        System.out.println("========================");

        // 방문 체크 구문
        // 현재 좌표에 퀸을 놓음으로써 이 후의 라인에서 퀸을 놓지 못하는 곳을 체크
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n + 4; j++) {
                int ny = curY + (dir[i][0] * j);
                int nx = curX + (dir[i][1] * j);
                if (ny >= 0 && nx >= 0 && nx < n && ny < n)
                    visit[ny][nx] = true;
            }
        }
        boolean[][] tmp = cpyArr(visit);



        Queue<Pair> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (!visit[curY + 1][i]) {
                // 다음 줄 에서 갈 수 있는 좌표를 큐에 저장
                q.add(new Pair(curY + 1, i));
            }
        }

        // 방문 체크한 노드들로 다음 재귀 시작
        // 큐에는 다음줄에 진행할 수 있는 좌표값이 들어가 있다.
        while (!q.isEmpty()) {
            Pair p = q.poll();
            func(visit, p.first, p.second);
            // 돌아오면 원래 상태로 배열 복구
            visit = tmp;

            System.out.println("=========방문 후========");
            printer(visit);
            System.out.println("========================");
        }
    }

    public static void main(String[] args) {
        // try (Scanner sc = new Scanner(new FileInputStream("input.txt"))) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            n = sc.nextInt();

            // boolean[][] visit = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                func(new boolean[n][n], 0, i);
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
        // } catch (Exception e) {
        // e.printStackTrace();
        // }
    }

    public static void printer(boolean[][] map) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j]) {
                    System.out.print("O ");
                } else {
                    System.out.print("X ");
                }
            }
            System.out.println();
        }
    }

    public static boolean[][] cpyArr(boolean[][] visit) {
        boolean[][] tmp = new boolean[visit.length][visit.length];
        for (int i = 0; i < visit.length; i++) {
            System.arraycopy(visit[i], 0, tmp[i], 0, visit[i].length);
        }
        return tmp;
    }

    static class Pair {
        int first;
        int second;

        Pair() {
        }

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
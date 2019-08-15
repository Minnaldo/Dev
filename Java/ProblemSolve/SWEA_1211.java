import java.util.*;
import java.io.*;

/**
 * Ladder 2
 */

public class SWEA_1211 {

    static int dist = 0, ans = 0;

    // x : arr.get(i); i: 0~arr.size();, aridx = i
    public static void solution(int[][] map, ArrayList<Integer> arr, int y, int x, int aridx) {
        int cnt = 100;
        int startx = x;
        for (int i = 0; i < 100; i++) {
            if (x - 1 >= 0 && map[i][x - 1] == 1) {
                // 왼쪽으로 가는 길이 있을 때
                cnt += Math.abs(x - arr.get(--aridx) - 1);
                x = arr.get(aridx);
            } else if (x + 1 < 100 && map[i][x + 1] == 1) {
                // 오른쪽으로 가는 길이 있을 때
                cnt += Math.abs(x - arr.get(++aridx) - 1);
                x = arr.get(aridx);
            }
        }

        if (map[99][x] == 1) {
            ans = dist >= cnt ? startx : ans;
            dist = cnt;
            System.out.println("dist=" + dist + "   cnt=" + cnt);
            System.out.println("x=" + x + "  startX=" + startx + "\tans=" + ans);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            for (int tc = 1; tc <= 1; tc++) {
                int t = sc.nextInt();
                ans = 0;
                dist = 98764312;
                int[][] map = new int[100][100];

                ArrayList<Integer> arr = new ArrayList<>();

                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < 100; j++) {
                        map[i][j] = sc.nextInt();
                    }
                }

                for (int i = 0; i < 100; i++) {
                    if (map[0][i] == 1) {
                        arr.add(i);
                    }
                }
                System.out.println(arr.toString());
                for (int i = 0; i < arr.size(); i++) {
                    solution(map, arr, 0, arr.get(i), i);
                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
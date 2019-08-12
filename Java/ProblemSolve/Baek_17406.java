import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

public class Baek_17406 {

    private static ArrayList<Tuple[]> arrPerm;
    private static Tuple[] inst;
    static int n, m;

    static class Tuple {
        int r, s, c;

        Tuple(int r, int s, int c) {
            this.r = r;
            this.s = s;
            this.c = c;
        }

    }

    public static void swap(Tuple[] arr, int a, int b) {
        Tuple tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    public static void swap(int[][] arr, int aY, int aX, int bY, int bX) {
        int tmp = arr[aY][aX];
        arr[aY][aX] = arr[bY][bX];
        arr[bY][bX] = tmp;
    }

    public static void perm(Tuple[] arr, int pivot) {
        if (pivot == arr.length) {
            //
            arrPerm.add(arr);
            return;
        }

        for (int i = pivot; i < arr.length; i++) {
            swap(arr, i, pivot);
            perm(arr, pivot + 1);
            swap(arr, i, pivot);
        }
    }

    public static int getMin(int[][] map) {
        int ans = 987654321;

        for (int i = 1; i < map.length - 1; i++) {
            int tmpSum = 0;
            for (int j = 1; j < map[0].length - 1; j++) {
                tmpSum += map[i][j];
            }
            ans = ans < tmpSum ? ans : tmpSum;
        }
        return ans;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new FileInputStream("input.txt"))) {
            // Scanner sc = new Scanner(System.in);
            n = sc.nextInt();
            m = sc.nextInt();
            int k = sc.nextInt();
            int[][] map = new int[n + 2][m + 2];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    map[i][j] = sc.nextInt();
                }
            }

            arrPerm = new ArrayList<>();
            inst = new Tuple[k];

            for (int i = 0; i < k; i++) {
                int r = sc.nextInt(), c = sc.nextInt(), s = sc.nextInt();
                inst[i] = new Tuple(r, s, c);
            }
            // 가능한 명령어 순서의 조합을 구한다.

            perm(inst, 0);
            int ans = 987654321;
            int cnt = 0;
            for (Tuple[] tArr : arrPerm) {
                int tmp = 0;

                int[][] tmpMap = cpyArr(map);
                System.out.println("Case " + cnt++);
                for (int i = 0; i < tArr.length; i++) {
                    System.out.println("r=" + tArr[i].r + " s=" + tArr[i].s + " c=" + tArr[i].c);
                    tmp = rotate(map, tArr[i].r, tArr[i].s, tArr[i].c);
                    ans = ans < tmp ? ans : tmp;
                }
                map = tmpMap;
                System.out.println("=======================================");
            }

            System.out.println(ans);

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static int rotate(int[][] map, int r, int s, int c) {
        // 배열을 회전시키는 로직
        for (int j = 1; j <= s; j++) {
            // 1 y 증가
            for (int dd = r - j; dd < r + j; dd++) {
                swap(map, dd, c - j, dd + 1, c - j);
            }
            // 2 x 증가
            for (int rr = c - j; rr < c + j; rr++) {
                swap(map, r + j, rr, r + j, rr + 1);
            }
            // 3 y 감소
            for (int uu = r + j; uu > r - j; uu--) {
                swap(map, uu, c + j, uu - 1, c + j);
            }
            // 4 x 감소
            for (int ll = c + j; ll > c - j; ll--) {
                swap(map, r - j, ll, r - j, ll - 1);
            }
        }
        return getMin(map);

    }

    public static int[][] cpyArr(int[][] map) {
        int[][] tmp = new int[map.length][map[0].length];
        for (int i = 0; i < map.length; i++) {
            System.arraycopy(map[i], 0, tmp[i], 0, map[i].length);
        }
        return tmp;
    }

}

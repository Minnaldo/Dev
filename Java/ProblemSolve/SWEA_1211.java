import java.util.*;
import java.io.*;

public class SWEA_1211 {

    static int dist, ans;
    static int[][] map;
    static ArrayList<Integer> arr;

    // x : arr.get(i); i: 0~arr.size();, aridx = i
    public static void solution(int x, int aridx) {
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

        ans = dist > cnt ? startx : ans;
        // 최소길이 갱신
        dist = dist >= cnt ? cnt : dist;
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            BufferedReader br = new BufferedReader(new InputStreamReader(fis));
            StringTokenizer st;
            for (int tc = 1; tc <= 10; tc++) {

                int t = Integer.parseInt(br.readLine());
                ans = 0;
                dist = 98764312;
                map = new int[100][100];
                arr = new ArrayList<>();

                for (int i = 0; i < 100; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < 100; j++) {
                        map[i][j] = Integer.parseInt(st.nextToken());
                    }
                }

                for (int i = 0; i < 100; i++) {
                    if (map[0][i] == 1) {
                        arr.add(i);
                    }
                }

                for (int i = 0; i < arr.size(); i++) {
                    solution(arr.get(i), i);
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
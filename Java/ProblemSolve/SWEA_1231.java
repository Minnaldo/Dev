import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class SWEA_1231 {

    static StringBuilder ans;
    static int n;
    static boolean[] visit;
    static String[] arr;

    // 중위순회 : 좌 - 중 - 우
    public static void recur(int curidx, int cnt) {
        int chidx = curidx * 2;
        if (chidx <= n && !visit[chidx]) {
            // 왼쪽 자식 노드로 넘어 갈 수 있을 때
            recur(chidx, cnt + 1);
        }
        // TODO why if ? not else
        if (chidx + 1 <= n && !visit[chidx + 1]) {
            // 오른쪽 자식으로 넘어 갈 수 있을 때
            ans.append(arr[curidx]);
            visit[curidx] = true;
            recur(chidx + 1, cnt + 1);
        } else {
            // 넘어갈 수 있는 자식노드가 하나도 없을 때
            ans.append(arr[curidx]);
            visit[curidx] = true;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int tc = 1; tc <= 1; tc++) {
            n = sc.nextInt();
            ans = new StringBuilder();
            arr = new String[n + 1];
            visit = new boolean[n + 1];
            sc.nextLine();
            // input
            for (int i = 0; i < n; i++) {
                String[] input = sc.nextLine().split(" ");
                arr[Integer.parseInt(input[0])] = input[1];
            }
            recur(1, 1);
            System.out.println("#" + tc + " " + ans.toString());
        }
    }
}
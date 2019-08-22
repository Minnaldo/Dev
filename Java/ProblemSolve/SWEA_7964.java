import java.io.*;
import java.util.*;

/**
 * * 부먹왕국의 차원관문
 */

public class SWEA_7964 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int limit = Integer.parseInt(st.nextToken());
                st = new StringTokenizer(br.readLine());

                ArrayList<Integer> arr = new ArrayList<>();
                for (int i = 0; i < n; i++)
                    arr.add(Integer.parseInt(st.nextToken()));

                // 결국엔 모든 지점은 한번씩은 방문하여야 한다.
                for (int i = 0; i < n - limit + 1; i++) {
                    boolean flag = false;
                    // 0번도시 ~ n-1 번 도시까지 탐색
                    for (int j = i; j < i + limit; j++) {
                        if (arr.get(j) == 1) {
                            i = j;
                            flag = true;
                            break;
                        }
                    }

                    if (!flag) {
                        // i 부터 limit사이에 관문이 없는경우
                        i += limit - 1;
                        arr.set(i, 1);
                        ans++;
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
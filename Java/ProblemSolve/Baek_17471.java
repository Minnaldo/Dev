import java.io.*;
import java.util.*;

// 순열/조합을 이용함
public class Baek_17471 {

    static int[] population;
    static int[][] map;
    static int answer = Integer.MAX_VALUE, n;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 지역구의 갯수
        n = Integer.parseInt(br.readLine());
        map = new int[n + 1][n + 1];
        population = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            population[i] = Integer.parseInt(st.nextToken());
        }

        // 각 구역의 연결정보를 인접행렬 형태로 저장
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            for (int j = 0; j < a; j++) {
                int dst = Integer.parseInt(st.nextToken());
                map[i][dst] = 1;
            }
        }

        for (int i = 1; i <= n / 2; i++) {
            // 로직 시작
            combi(new int[i], 0, new boolean[n + 1]);
        }

        // 결과 출력
        answer = answer == Integer.MAX_VALUE ? -1 : answer;
        System.out.println(answer);
    }

    static public void combi(int[] sel, int idx, boolean[] visit) {
        if (sel.length == idx) {
            // sel 배열에는 지금까지 뽑은 지역구의 조합이 들어있다.
            int[] tmpArr = new int[n - sel.length];
            int tmpidx = 0;
            for (int i = 1; i <= n; i++) {
                if (!visit[i]) {
                    tmpArr[tmpidx++] = i;
                }
            }

            if (chk(sel) && chk(tmpArr)) {
                func(sel, tmpArr);
            }

            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                sel[idx] = i;
                combi(sel, idx + 1, visit);
                visit[i] = false;
            }
        }
    }

    // 하나의 지역구 셋이 연결되어있는지 확인
    // 들어온 배열은 인덱스 정보를 갖고있다.
    static public boolean chk(int[] arr) {
        boolean[] visit = new boolean[n + 1];
        // 길이가 0일때도 체크를 해줘야 할 듯
        int start = arr[0];
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visit[start] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int i = 0; i < arr.length; i++) {
                if (!visit[arr[i]] && map[cur][arr[i]] == 1) {
                    q.add(arr[i]);
                    visit[arr[i]] = true;
                }
            }
        }

        for (int i = 0; i < arr.length; i++) {
            if (!visit[arr[i]]) {
                return false;
            }
        }
        return true;
    }

    // 두개로 나뉘어진 지역구의 인구수 차가 가장 작은 값을 구한다.
    // 들어온 배열은 인덱스 정보를 갖고있다.
    static public void func(int[] arr, int[] arr2) {
        int sum = 0, sum2 = 0;

        for (int i = 0; i < arr.length; i++) {
            sum += population[arr[i]];
        }
        for (int i = 0; i < arr2.length; i++) {
            sum2 += population[arr2[i]];
        }

        answer = Math.min(answer, Math.abs(sum - sum2));
    }
}
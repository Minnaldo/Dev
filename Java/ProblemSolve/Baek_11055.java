import java.io.*;
import java.util.*;

public class Baek_11055 {

    static int[] arr;
    static ArrayList<Integer> result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        result = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        result.add(arr[0]);
        for (int i = 1; i < n; i++) {
            int idx = lowerbound(arr[i], 0, result.size() - 1);
            // System.out.println(idx);
            result.set(idx, arr[i]);
        }

        System.out.println(result.toString());
        // int ans = 0;
        // for (int val : result) {
        // ans += val;
        // }
        // System.out.println(ans);
    }

    // 결과 배열을 이분탐색
    // 키보다 작거나 같은곳의 인덱스를 찾아 리턴
    static int lowerbound(int key, int start, int end) {
        int mid = (start+end)/2;
        result.get(mid)
    }
}
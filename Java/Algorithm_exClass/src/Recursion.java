public class Recursion {

    static int ans;

    static void recur(int[] arr, int n, int sum) {
        // 기저파트, 재귀함수가 더이상 불리지 않을 종료조건
        if (n == arr.length) {
            ans += sum;
            return;
        }

        // do something
//        System.out.println(arr[n]);

        // 계수를 증감시키며 재귀호출을 하는 영역
        recur(arr, n + 1, sum + arr[n]);
        recur(arr, n + 1, sum * arr[n]);
    }

    public static void main(String[] args) {
//        int n = 0;
//        while (n < 5) {
//            System.out.println("실행이 될까요?");
//            // 반복 계수
//            n++;
//        }
        ans = 0;
        int[] arr = {1, 3, 5};
        recur(arr, 0, 1);
        System.out.println(ans);
    }
}

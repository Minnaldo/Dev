public class powerset_Sum_recur {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4 };
        recur(arr, 0, 0);
    }

    static void recur(int[] arr, int idx, int sum) {
        if (idx == arr.length) {
            System.out.println(sum);
            return;
        }

        // 선택 한것
        recur(arr, idx + 1, sum + arr[idx]);
        // 선택 안한 것
        recur(arr, idx + 1, sum);
    }
}
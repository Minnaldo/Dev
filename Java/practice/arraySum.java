public class arraySum {

    public static void arrSum(int[] arr, int sum, int idx) {

        if (idx == arr.length) {
            System.out.println(sum);
            return;
        }

        arrSum(arr, sum + arr[idx], idx + 1);
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        arrSum(arr, 0, 0);
    }
}
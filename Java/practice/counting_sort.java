import java.util.Arrays;

/**
 * 카운팅 정렬 각 숫자별로 빈도를 세고, 나보다 작은 수의 갯수 + 1의 자리가 내자리
 */

public class counting_sort {
    public static void main(String[] args) {
        int[] arr = { 0, 4, 1, 3, 1, 2, 4, 1 };
        int[] tmp = new int[arr.length + 1];

        int[] sorted = new int[arr.length];
        int[] count = new int[arr.length + 1];

        // counting frequently
        for (int i = 0; i < arr.length; i++) {
            tmp[arr[i]]++;
            count[arr[i]]++;
        }

        // 누적 빈도 구하기
        for (int i = 1; i < tmp.length; i++) {
            count[i] += count[i - 1];
        }

        // System.out.println("누적합");
        // System.out.println(Arrays.toString(count));

        for (int i = 0; i < arr.length; i++) {
            sorted[--count[arr[i]]] = arr[i];
        }

        // idx : 현재까지 정렬된 원소의 갯수
        int idx = 0;
        for (int i = 0; i < tmp.length; i++) {
            if (tmp[i] != 0) {
                for (int j = idx; j < idx + tmp[i]; j++) {
                    arr[j] = i;
                }
                idx += tmp[i];
            }
        }

        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(sorted));
    }
}
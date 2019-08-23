import java.util.Arrays;

public class Combination {
    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7};

//        combiation(arr, 0, new int[3], 0);
//        perm_re(arr, new int[3], 0);
        perm(arr, new int[3], 0, new boolean[arr.length]);
    }

    /**
     * 조합 (Combination) nCr : 순서에 상관없이 r개를 뽑는 경우의 수
     *
     * @param arr 숫자를 뽑을 원본 배열...
     * @param idx 원본 배열을 탐색하는 인덱스
     * @param sel 뽑혀진 숫자를 저장할 배열
     * @param k   뽑은 숫자를 기록할 인덱스
     */
    static void combiation(int[] arr, int idx, int[] sel, int k) {
        // 기저조건 1
        if (k == sel.length) {
            // 모두 고름
            // sel변수에 저장이 되므로, sel을 출력하면, arr.length개의 수 중, sel.length개의 수를 뽑는 경우의 수가 된다.
            System.out.println(Arrays.toString(sel));
            return;
        }
        // 기저조건 2
        if (idx == arr.length) {
            // 더 이상 탐색할 숫자가 없음
            return;
        }

        // 고르는 경우 : 이번에 담아야할 위치인 k번째 sel 배열칸에 지금 탐색하는 arr의 idx번째 원소를 담는다.
        sel[k] = arr[idx];
        combiation(arr, idx + 1, sel, k + 1);
        // 안담는 경우 : idx만 증가시켜서 검사하는 배열만 한칸 이동
        // 다음 실행시 sel의 k번째 칸에 arr의 idx+1번째 값이 덮어 씌워진다
        combiation(arr, idx + 1, sel, k);
    }

    /**
     * 중복 순열 Repetition Permutation
     *
     * @param arr 숫자를 뽑을 원본 배열...
     * @param sel 뽑혀진 숫자를 저장할 배열
     * @param k   뽑은 숫자를 기록할 인덱스
     */
    static void perm_re(int[] arr, int[] sel, int k) {
        if (k == sel.length) {
            // 다 고름
            System.out.println(Arrays.toString(sel));
            return;
        }

        // 모든 순간에서 전부를 선택할 수 있으므로
        // 반복문을 통해 전체 경우를 집어넣어준다.
        for (int i = 0; i < arr.length; i++) {
            sel[k] = arr[i];
            perm_re(arr, sel, k + 1);
        }
    }

    /**
     * 순열(Permutation) nPr : n개중 r개를 중복없이 순서에 맞게 고르는 경우의 수
     *
     * @param arr
     * @param sel
     * @param k
     * @param visit
     */

    static void perm(int[] arr, int[] sel, int k, boolean[] visit) {
        if (k == sel.length) {
            // 다 고름
            System.out.println(Arrays.toString(sel));
            return;
        }

        for (int i = 0; i < arr.length; i++) {
            if (!visit[i]) {
                sel[k] = arr[i];
                visit[i] = true;    // i번째 원소 사용 체크
                // 체크한 이유 : 다음 단계 선택 시, 이미 고른 원소는 선택하지 않기 위해
                perm(arr, sel, k + 1, visit);
                visit[i] = false;
            }
        }


    }
}

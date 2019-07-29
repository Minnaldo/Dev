/**
 *  for-each 문의 구조
 *  for(type var : iterate){
 *      body-of-loop
 *  }
 *  // 출처 : wikidocs
 *  월말 평가 7월
 */

public class for_each_test {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };

        for (int aa : arr) {
            if (aa % 2 == 0) {
                aa += 1;
            }
        }

        for (int val : arr) {
            System.out.print(val + " ");
        }
    }
}
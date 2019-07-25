/**
 *  * 재귀함수 : 스택구조와 다중 재귀의 관계
 */

public class recur_test {
    public static void main(String[] args) {
        printN(3);
    }

    static void printN(int n) {
        if (n == 0) {
            return;
        }

        System.out.println(n);
        printN(n - 1);
        printN(n - 1);
        System.out.println(n);
    }
}
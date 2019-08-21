/**
 * * 분할 정복 기법으로 power를 구한다 * 재귀함수를 이용한 방법
 */

public class Recur_Power {

    // @param : x 밑
    // @param : n 승수

    // x^n을 구할 때, x^n = x^(n/2) * x^(n/2) (n가 짝수)
    // x^n = x^((n-1)/2) * x^((n-1)/2) * x (n가 홀수)
    static int rec_pow(int x, int n) {
        if (n == 1)
            return x;

        if (n % 2 == 0) {
            int tmp = rec_pow(x, n / 2);
            return tmp * tmp;
        } else {
            int tmp = rec_pow(x, n / 2);
            return tmp * tmp * x;
        }
    }

    public static void main(String[] args) {

        System.out.println(rec_pow(2, 4));
    }
}
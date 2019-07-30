package chap07;

import java.util.Scanner;
import java.util.zip.DataFormatException;

public class ExceptionTest2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        try {
            // 메소드에서 예외를 넘겨받는 코드
            int res = div(sc.nextInt(), sc.nextInt());
        } catch (ArithmeticException e) {
            e.printStackTrace();
        } catch (DataFormatException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // throws를 통해 div함수를 호출한 쪽에 에러를 넘겨준다.
    // ArithmeticException 발생 가능성 : 0으로 나눌 때
    static int div(int a, int b) throws ArithmeticException, MyDataInputException {  // throws에는 여러개가 들어갈 수 있다.
        int res = 0;
        if (b == 0) {
            throw new MyDataInputException("0을 입력하지 마세요");    // Exception instance를 만들어 호출한 곳에 에러를 보낸다.
        }
        // 에러가 발생한 코드의 다음 코드는 실행되지않고 메소드가 끝이 난다.
        res = a / b;
        return res;
    }
}

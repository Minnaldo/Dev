package chap09;

import chap09.LambdaTest.Calc;

public class LambdaTest2 {
    public static void main(String[] args) {
        Calc c = (a, b) -> a * b;
        Printer p = s -> System.out.println(s);

        // Printer는 문자열을 인자로 받으므로, 리턴값을 String으로 바꾸어 주어야 한다.
        p.print(c.cal(3, 5) + "");
    }
}

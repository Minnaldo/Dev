package chap07;

import java.util.Scanner;

public class ExceptionTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("res : " + sc.nextInt() / sc.nextInt());

            System.out.println("Program end");
        } catch (ArithmeticException ae) {
            // exception class에 존재, 예외 발생상황을 프린트해줌
            ae.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println("finally");
        }
    }
}

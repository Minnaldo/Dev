package app.programming.chap04;

/**
 *  Overloading을 연습한다
 */

public class CalcMain {
    public static void main(String[] args) {
        Calc c = new Calc();

        System.out.println(c.add(4, 3));
        System.out.println(c.minus(6, 3));

        c.add(4, 3);
        c.add(3.f, 3);
        c.add(3, 3.f);
    }
}
package chap09;

interface Printer {
    void print(String str);
}

public class LambdaTest {
    public static void main(String[] args) {
        // Printer를 바로 구현함
        // Legacy
        Printer p = new Printer() {
            @Override
            public void print(String str) {
                System.out.println(str);
            }
        };

        p.print("Hello");

        // Lambda Expression
        // 인터페이스 안에 추상 메소드가 한개 있을 때만 가능함
        Printer p2 = (String s) -> {
            System.out.println(s);
        };

        p2.print("hello");
        // 중괄호를 빼도 된다
        Printer p3 = (String s) -> System.out.println(s);
        p3.print("Lambda2");

        // 변수타입을 안적어 줘도 된다
        Printer p4 = (s) -> System.out.println(s);
        p4.print("Lambda3");

        // 모든 괄호가 필요 없다
        Printer p5 = s -> System.out.println(s);
        p5.print("Lambda4");

        // Runnable의 run 메소드를 익명함수로 구현한 것
        new Thread(() -> {
            System.out.println("Thread start");
        }).start();

        // Runnable에 Legacy 인터페이스 구현방식을 사용함
        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println(this.getClass().getSimpleName());
            }
        });

        // 변수이름을 안맞춰 줘도 된다
        Calc add = (q, qq) -> {
            return q + qq;
        };
        Calc add2 = (a,b)->{return a+b;};
        // 자동으로 결과값이 리턴된다.
        Calc add3 = (a,b)->a+b;

    }

    interface Calc {
        int cal(int a, int b);
    }
}

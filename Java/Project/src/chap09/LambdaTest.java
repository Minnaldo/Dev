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
        Printer p2 = (String s) -> {
            System.out.println(s);
        };

        p2.print("hello");
    }
}

package app.programming.chap04;

public class Calc {
    // method overlaod
    int add(int a, int b) {
        return a + b;
    }

    // Overloading 된 메소드
    float add(float a, int b) {
        return a + b;
    }

    // Overloading 된 메소드
    float add(int a, float b) {
        return a + b;
    }

    int minus(int a, int b) {
        return a - b;
    }
}
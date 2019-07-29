package chap06two;

public class Frog extends Animal {
    public void swimming() {
        System.out.println("개구리가 수영해요");
    }

    @Override
    public void walk() {
        System.out.println("개구리가 뛰어요");
    }
}

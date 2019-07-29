package chap06two;

public class Bird extends Animal implements IFly {
    @Override
    public void fly() {
        System.out.println("새가 날아다닙니다");
    }

    @Override
    public void walk() {
        System.out.println("새가 뛰어다닙니다");
    }
}

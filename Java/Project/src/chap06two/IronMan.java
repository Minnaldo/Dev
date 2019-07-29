package chap06two;

public class IronMan extends Human implements IFly, IRazer {
    @Override
    public void walk() {
        System.out.println("아이언맨이 걷습니다.");
    }

    @Override
    public void fly() {
        System.out.println("아이언맨이 날아다닙니다");
    }

    @Override
    public void attack() {
        System.out.println("아이언맨이 레이저를 쏩니다");
    }
}

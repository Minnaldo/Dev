package chap06two;

/**
 * 인터페이스와 상속, 2차 상속
 */

public class MainTest {
    public static void main(String[] args) {
        // 모두 Object나 Animal로 업캐스팅이 가능함
        Bird b = new Bird();
        Frog f = new Frog();
        Human h = new Human();
        Lion l = new Lion();
        Superman s = new Superman();
        IronMan iron = new IronMan();


        toFly(b);
        toFly(s);
        toWalk(b);
        toWalk(s);

        toAttck(iron);
    }

    // IFly를 implements 한 클래스만 접근 가능함
    public static void toFly(IFly f) {
        f.fly();
    }

    public static void toWalk(Animal a) {
        a.walk();
    }

    public static void toAttck(IRazer ir){
        ir.attack();
    }
}

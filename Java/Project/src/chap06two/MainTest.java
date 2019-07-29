package chap06two;

public class MainTest {
    public static void main(String[] args) {
        // 모두 Object나 Animal로 업캐스팅이 가능함
        Bird b = new Bird();
        Frog f = new Frog();
        Human h = new Human();
        Lion l = new Lion();
        Superman s = new Superman();


        toWalk(b);
        toWalk(f);
        toWalk(h);
        toWalk(l);
        toWalk(s);

        toFly(s);
        toFly(b);
    }
    public static void toFly(IFly ff){
        ff.fly();
    }

    public static void toWalk(Animal a) {
        a.walk();
    }


}

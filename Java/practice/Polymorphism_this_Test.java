/**
 * ! this는 객체의 타입을 따라간다 ! 코드에서 new Child()를 하였으므로 객체의 타입은 Child가 된다 ! 그러므로
 * c.work()를 하면 Parent의 show가 불리지만, show 메소드에서 this.show()는 Child클래스의 show메소드를
 * 부르게 되므로 ! 출력은 AWB가 된다
*  * 월말 평가 7월
 */

class Parent {
    void work() {
        this.show();
        System.out.println("W");
    }

    void show() {
        System.out.println("A");
    }
}

class Child extends Parent {
    void show() {
        super.show();
        System.out.println("B");
    }
}

public class Polymorphism_this_Test {
    public static void main(String[] args) {
        Parent c = new Child();
        c.work();
    }
}
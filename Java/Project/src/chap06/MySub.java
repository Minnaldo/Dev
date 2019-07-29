package chap06;

// interface는 다중으로 상속받을 수 있다.
public class MySub extends Object implements MyInter, MyInter2{
    @Override
    public void disable() {
        // from MyInter2
    }

    @Override
    public void show() {
        // from MyInter
    }
}

package chap06;

// 추상 메소드가 존재하는 클래스는 abstract키워드를 통해 추상클래스로 만들어주어야 한다.
// 추상 메소드는 추상메소드 뿐만 아니라 일반 메소드도 갖고 있을 수 있다.
public abstract class AbstractTest {
    public abstract void show(); // 구현부가 없는 메소드, 구현부가 없는 메소드는 abstract 키워드를 이용하여 추상 메소드를 만들어야함
    // 추상 메소드 : body가 없는 메소드
}

// abstract클래스를 상속 받을 때는, 추상클래스의 메소드를 오버라이딩 하거나, 똑같이 서브클래스도 abstract키워드를 이용해 추상클래스로 변경해주어야 한다.
class sub extends AbstractTest {
    // 추상클래스의 메소드를 오버라이딩
    @Override
    public void show() {

    }
}

class sub2 extends AbstractTest {
    @Override
    public void show() {

    }
}
package chap07;

public class Generic<Type> {
    Type i;

    public Type getI() {
        return i;
    }

    public void setI(Type i) {
        this.i = i;
    }
}

// 상속 받을 때, super 클래스의 generic 타입을 지정할 수 있다.
class Sub extends Generic<String> {  // supper class의 generic(Type)을 String으로 받는다

    @Override
    public String getI() {
        return super.getI();
    }

    @Override
    public void setI(String i) {
        super.setI(i);
    }
}
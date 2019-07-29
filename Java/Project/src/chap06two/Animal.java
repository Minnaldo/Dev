package chap06two;

public abstract class Animal {
    // 추상 클래스의 일반 메소드를 오버라이딩 하지 않으면, 상위 클래스(추상 클래스)의 메소드가 호출이 된다
    public String whoami() {
        return "동물";
    }

    public abstract void walk();
}

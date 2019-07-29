package chap06;

public class Maintest2 {
    public static void main(String[] args) {
        AbstractTest s = new sub(); // AbstractTest를 상속받은 sub클래스를 객체화
        s.show();   // sub에서 overriding한 show 메소드를 호출

        AbstractTest s2 = new sub2();   // AbstractTest를 상속받았으므로, sub2는 AbstarctTest 클래스로 업캐스팅이 가능함

        AbstractTest[] arr = new AbstractTest[2];
        arr[0] = s;
        arr[1] = s2;

        toShow(s);
        toShow(s2);
    }

    static void toShow(AbstractTest at) {
        at.show();
    }
}

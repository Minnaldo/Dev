package app.programming.chap04;

public class PersonMain {
    public static void main(String[] args) {
        Person p = new Person();
        // 클래스의 `.`은 접근 지정자
        p.name = "둘리";
        p.age = 8;
        p.gender = false;
        p.addr = "쌍문동";
        // 객체 p는 reference counter가 0이되면 사라진다.

        System.out.println(p.name);
        System.out.println(p.age);
        System.out.println(p.gender);
        System.out.println(p.addr);

        Person p2 = new Person();
        p2.name = "고길동";
        p2.age = 40;
        p.gender = false;
        p.addr = "쌍문동";
    }
}
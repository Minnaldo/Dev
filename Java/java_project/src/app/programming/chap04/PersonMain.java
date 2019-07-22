package app.programming.chap04;

public class PersonMain {
    public static void main(String[] args) {

        Person p = new Person("홍길동", 21, false, "장덕동");
        // p.name="둘리";
        // p.age=8;
        // p.gender=false;
        // p.addr="쌍문동";

        Person p2 = new Person("둘리", 8, false, "쌍문동");

        // p2.name = "고길동";
        // p2.age = 40;
        // p2.gender=false;
        // p2.addr="쌍문동";

        Person p3 = new Person();

        System.out.println(p.info());
        System.out.println(p2.info());
    }
}
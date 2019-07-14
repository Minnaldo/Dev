class Person {
    /* 여기에 코드를 작성해 주세요! */
    String name;
    int age;

    Person() {
        this("이름없음", 1); // Person(String, int) 생성자 호출
    }

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    Person returnItSelf() {
        return this;
    }
}

public class class_test {
    public static void main(String[] args) {
        /* 여기에 코드를 작성해 주세요! */
        Person noName = new Person();
        System.out.println(noName.name);
        System.out.println(noName.age);

        Person p = noName.returnItSelf(); // Person 클래스의 객체, noName의 주소값을 반환
        Person p2 = noName;
        System.out.println(p);
        System.out.println(noName);
        System.out.println(p.name);

        System.out.println(p2);
    }
}
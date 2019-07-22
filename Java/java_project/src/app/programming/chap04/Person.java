package app.programming.chap04;

/** Person 정보 객체 */
public class Person {
    /** 이름 */
    String name;
    /** 나이 */
    int age;
    /** 성별 */
    boolean gender;
    /** 주소 */
    String addr;

    /** Constructor */
    // default constructor
    Person() {
        this("홍길동", 21); // name과 age를 갖고있는 생성자를 호출한다
        // this는 person class를 가리킨다 ( 정확히는 객체 )
        // this.addr
        // this.age
        // this.name
        // this.gender
    }

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    Person(String name, int age, boolean gender, String addr) {
        System.out.println("생성자 호출");
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.addr = addr;
    }

    /** 정보 */
    String info() {
        return "name=" + name + ", age=" + age + ", gender=" + gender + ", addr=" + addr;
    }
}

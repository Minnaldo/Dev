package programming.chap04;

public class Person {
    // 이름
    String name;
    // 나이
    int age;
    // 성별
    boolean gender;
    // 주소
    String addr;

    String info(){
        String str = "name="+name+", age="+age+", gender="+gender+", addr="+addr;
        return str;
    }
}
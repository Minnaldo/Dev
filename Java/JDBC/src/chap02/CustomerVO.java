package chap02;

// Data를 저장하는 클래스 ==> VO클래스라 한다
// VOClass = Value Obejct Class

public class CustomerVO {
    private int num;


    private String name;
    private int age;
    private String addr;

    public CustomerVO() {
    }

    public CustomerVO(int num, String name, int age, String addr) {
        this.num = num;
        this.name = name;
        this.age = age;
        this.addr = addr;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddr() {
        return addr;
    }

    public void setAddr(String addr) {
        this.addr = addr;
    }

    @Override
    public String toString() {
        return "CustomerVO{" +
                "num=" + num +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", addr='" + addr + '\'' +
                '}';
    }
}

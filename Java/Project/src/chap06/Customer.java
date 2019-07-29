package chap06;

public class Customer {
    int age;
    String name;

    // equals 오버라이딩
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Customer) {
            Customer target = (Customer) obj;
            if (this.name.equals(target.name) && this.age == target.age) {
                return true;
            }
        }
        return false;
    }
}

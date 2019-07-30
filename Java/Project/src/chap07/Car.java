package chap07;

// Data를 저장하는 클래스 Entity bean이라 한다
public class Car implements Comparable<Car> {
    String num;
    int price;

    public Car() {
    }

    public Car(String num, int price) {
        this.num = num;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Car{" +
                "num='" + num + '\'' +
                ", price=" + price +
                '}';
    }

    @Override
    public int compareTo(Car o) {
        if (this.num.compareTo(o.num) > 0) {
            return 1;
        }
        return -1;
    }
}

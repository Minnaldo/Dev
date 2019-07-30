package chap07;

public class GenericMain {

    class Car{}

    public static void main(String[] args) {
        Generic<Car> g = new Generic();

        Car i = g.getI();


    }
}

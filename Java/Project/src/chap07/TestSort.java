package chap07;

import java.util.ArrayList;
import java.util.Arrays;

public class TestSort {
    public static void main(String[] args) {

        Car[] cars = new Car[5];
        cars[0] = new Car("11", 50000);
        cars[1] = new Car("55", 69000);
        cars[2] = new Car("22", 39000);
        cars[3] = new Car("33", 89000);
        cars[4] = new Car("88", 29000);

        Arrays.sort(cars);

        System.out.println(Arrays.toString(cars));

        ArrayList<Car> list = new ArrayList<>();
        list.add(new Car("11", 50000));
        list.add(new Car("55", 69000));
        list.add(new Car("22", 39000));
        list.add(new Car("33", 89000));
        list.add(new Car("88", 29000));

        for (Car car : list) {
            System.out.println(car.toString());
        }
    }
}

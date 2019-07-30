package chap07;

import java.util.Collection;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class setTest {
    // set 계열을 toString()을 호출 할 경우, 갖고있는 목록을 출력한다.
    public static void main(String[] args) {
        TreeSet<String> set = new TreeSet<>();

        set.add("Seoul");
        set.add("Gwangju");
        set.add("Gumi");
        set.add("DaeJeon");

        for (Object o : set) {
            System.out.println(o);
        }

        TreeSet<Car> set2 = new TreeSet<>();
        set2.add(new Car());
        set2.add(new Car());
        set2.add(new Car());

        for(Car car : set2){
            System.out.println(car.toString());
        }
    }
}

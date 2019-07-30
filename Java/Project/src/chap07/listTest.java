package chap07;

import java.util.ArrayList;
import java.util.List;

public class listTest {
    // 리스트는 중복 허용
    // 순서가 존재
    // list 또한 object 상속으로 인해 toString()이 존재하며, 갖고있는 목록을 출력한다.
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();

        // list도 collection을 상속받으므로, add 메소드가 존재한다.
        list.add(30);
        list.add(40);
        list.add(20);
        list.add(90);
        list.add(90);
        list.get(3);
        System.out.println(list.toString());

        for(Integer o : list){
            System.out.println(o);
        }
    }
}

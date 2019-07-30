package chap07;

import java.util.HashMap;
import java.util.Map;

public class MapTest {
    public static void main(String[] args) {
        Map<Integer, String> m = new HashMap<>();

        m.put(1, "seoul");
        m.put(2, "GwanJu");
        m.put(3, "DaeJeon");
        m.put(4, "GuMi");


        for (Integer key :
                m.keySet()) {
            
        }
    }
}

package chap11.sax;

import java.util.ArrayList;

public class MySaxMain {
    public static void main(String[] args) {

        ArrayList<Check> list = new MySAXParser().getContent("result.xml");
        for (Check c : list) {
            System.out.println(c);
        }
    }
}
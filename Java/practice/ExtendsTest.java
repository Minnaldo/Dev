import java.util.*;
import java.io.*;

public class ExtendsTest {
    public static void main(String[] args) {
        Car c = new Bus();

        System.out.println(c.str);

        c.print();

    }
}

class Car {

    String str = "Car string";

    public void print() {
        System.out.println("Cararararar");
    }

    Car() {
    }
}

class Bus extends Car {

    String str = "Bus string";

    public void print() {
        System.out.println("BUsusususus");
    }

    Bus() {
    }
}
package chap06;

public class MainTest {
    public static void main(String[] args) {
        Customer c = new Customer();
        Customer c2 = new Customer();
        c.name = "kim";
        c.age = 10;

        c2.name = "kim";
        c2.age = 10;

        if (c.equals(c2)) {
            System.out.println("same");
        } else {
            System.out.println("diff");
        }

    }
}

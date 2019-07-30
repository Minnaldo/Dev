package hw_java_0730;

public class Refrigerator extends Product {
    private int liter;

    public Refrigerator() {
    }

    public Refrigerator(int num, String name, int price, int stock, int liter) {
        super(num, name, price, stock);
        this.liter = liter;
    }

    public int getLiter() {
        return liter;
    }

    public void setLiter(int liter) {
        this.liter = liter;
    }

    @Override
    public String toString() {
        return "Refrigerator{" +
                "num=" + super.getNum() +
                ", name='" + super.getName() + '\'' +
                ", price=" + super.getPrice() +
                ", stock=" + super.getStock() +
                "liter=" + liter +
                '}';
    }
}

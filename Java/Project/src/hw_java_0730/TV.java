package hw_java_0730;

public class TV extends Product {
    private int inch;

    public int getInch() {
        return inch;
    }

    public void setInch(int inch) {
        this.inch = inch;
    }

    @Override
    public String toString() {
        return "TV{" +
                "num=" + super.getNum() +
                ", name='" + super.getName() + '\'' +
                ", price=" + super.getPrice() +
                ", stock=" + super.getStock() +
                "inch=" + inch +
                '}';
    }

    public TV(int num, String name, int price, int stock, int inch) {
        super(num, name, price, stock);
        this.inch = inch;
    }

    public TV() {
    }
}

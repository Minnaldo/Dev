package hw_java_0729;

public class TV extends Product {
    private int inch;

    @Override
    public String toString() {
        return "TV{" +
                "ProductNum=" + super.getProNum() +", \""+
                "Name=" + super.getName() +", \""+
                "Price=" + super.getPrice() +", \""+
                "Stock=" + super.getStock() +", \""+
                "inch=" + inch +"\""+
                '}';
    }

    public int getInch() {
        return inch;
    }

    public void setInch(int inch) {
        this.inch = inch;
    }

    public TV(int proNum, String name, int price, int stock, int inch) {
        super(proNum, name, price, stock);
        this.inch = inch;
    }

    public TV() {
    }
}

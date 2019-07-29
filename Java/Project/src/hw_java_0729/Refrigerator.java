package hw_java_0729;

public class Refrigerator extends Product {
    private int liters;

    public Refrigerator(int proNum, String name, int price, int stock, int liters) {
        super(proNum, name, price, stock);
        this.liters = liters;
    }

    public Refrigerator() {

    }

    @Override
    public String toString() {
        return "Refrigerator{" +
                "ProductNum="+super.getProNum()+
                "Name="+super.getName()+
                "Price="+super.getPrice()+
                "Stock="+super.getStock()+
                "liters=" + liters +
                '}';
    }

    public int getLiters() {
        return liters;
    }

    public void setLiters(int liters) {
        this.liters = liters;
    }
}

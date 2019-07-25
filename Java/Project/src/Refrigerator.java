public class Refrigerator extends Product {

    // Refrigerator의 특성
    private int volume;

    public Refrigerator(int productNum, String name, int price, int stock, int volume) {
        super(productNum, name, price, stock);
        this.volume = volume;
    }

    public int getVolume() {
        return volume;
    }

    @Override
    public String toString() {
        return "Refrigerator { Product Number=" + super.getProductNum() +
                ", Name=" + super.getName() +
                ", Price=" + super.getPrice() +
                ", Stock=" + super.getStock() +
                ", volume=" + volume +
                '}';
    }
}

package hw_java_0729;

public class Product {
    private int proNum;
    private String name;
    private int price;
    private int stock;

    @Override
    public String toString() {
        return "Product{" +
                "proNum=" + proNum +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", stock=" + stock +
                '}';
    }


    public Product(int proNum, String name, int price, int stock) {
        this.proNum = proNum;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }

    public Product() {
    }

    public int getProNum() {
        return proNum;
    }

    public void setProNum(int proNum) {
        this.proNum = proNum;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }
}

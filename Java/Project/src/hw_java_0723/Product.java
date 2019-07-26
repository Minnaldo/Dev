package hw_java_0723;

public class Product {
    // 상품 공통정보를 담는 클래스
    private int productNum;
    private String name;
    private int price;
    private int stock;

    public Product(int productNum, String name, int price, int stock) {
        this.productNum = productNum;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }



    public int getProductNum() {
        return productNum;
    }

    public String getName() {
        return name;
    }

    public int getPrice() {
        return price;
    }

    public int getStock() {
        return stock;
    }

    public void setProductNum(int productNum) {
        this.productNum = productNum;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    @Override
    public String toString() {
        return "hw_java_0723.Product{" +
                "productNum=" + productNum +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", stock=" + stock +
                '}';
    }
}

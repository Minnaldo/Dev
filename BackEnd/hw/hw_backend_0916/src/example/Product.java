package example;

public class Product {
    private int number;
    private String name;
    private String price;
    private String desc;

    public Product(int number, String name, String price, String desc) {
        this.number = number;
        this.name = name;
        this.price = price;
        this.desc = desc;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPrice() {
        return price;
    }

    public void setPrice(String price) {
        this.price = price;
    }

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    @Override
    public String toString() {
        return "Product{" +
                "number=" + number +
                ", name='" + name + '\'' +
                ", price='" + price + '\'' +
                ", desc='" + desc + '\'' +
                '}';
    }
}

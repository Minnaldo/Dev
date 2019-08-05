package ws_java_0805;

import java.io.Serializable;

public class Magazine extends Book implements Serializable {
    private int month;
    private int year;

    public Magazine() {
    }

    public Magazine(String isbn, String title, int price, int quantity, int month) {
        super(isbn, title, price, quantity);
        this.month = month;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    @Override
    public String toString() {
        return "Magazine{" +
                "isbn='" + super.getIsbn() + '\'' +
                ", title='" + super.getTitle() + '\'' +
                ", price=" + super.getPrice() + '\'' +
                ", quantity=" + super.getQuantity() + '\'' +
                ", year=" + year +
                ", month=" + month +
                '}';
    }
}

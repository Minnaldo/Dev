package ws_java_0729;

public class Magazine extends Book {
    private int year;
    private int month;

    @Override
    public String toString() {
        return "Magazine{" +
                "isbn='" + super.getIsbn() + '\'' +
                ", title='" + super.getTitle() + '\'' +
                ", author='" + super.getAuthor() + '\'' +
                ", publisher='" + super.getPublisher() + '\'' +
                ", price=" + super.getPrice() +
                ", desc='" + super.getDesc() + '\'' +
                ", year=" + year +
                ", month=" + month +
                '}';
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

    public Magazine(String isbn, String title, String author, String publisher, int price, String desc, int year, int month) {
        super(isbn, title, author, publisher, price, desc);
        this.year = year;
        this.month = month;
    }

    public Magazine() {
    }
}

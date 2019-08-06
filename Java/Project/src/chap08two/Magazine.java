package chap08two;

public class Magazine extends Book {
    private int month;

    public Magazine() {
    }

    // 부모 클래스에 있는 변수는 부모로 넘기고, 자식 클래스의 변수는 자식에서 처리
    public Magazine(String isbn, String title, int price, int month) {
        super(isbn, title, price);
        this.month = month;
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
                "Isbn=" + super.getIsbn() +
                "Title=" + super.getTitle() +
                "Price=" + super.getPrice() +
                "month=" + month +
                '}';
    }
}

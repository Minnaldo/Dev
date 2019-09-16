package model;

public class Book {
    // singletone pattern

    private String isbn;
    private String title;
    private String catalogue;
    private String nation;
    private String publishDate;
    private String publisher;
    private String author;
    private String price;
    private String desc;

    public Book(String isbn, String title, String catalogue, String nation, String publishDate, String publisher, String author, String price, String desc) {
        this.isbn = isbn;
        this.title = title;
        this.catalogue = catalogue;
        this.nation = nation;
        this.publishDate = publishDate;
        this.publisher = publisher;
        this.author = author;
        this.price = price;
        this.desc = desc;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getCatalogue() {
        return catalogue;
    }

    public void setCatalogue(String catalogue) {
        this.catalogue = catalogue;
    }

    public String getNation() {
        return nation;
    }

    public void setNation(String nation) {
        this.nation = nation;
    }

    public String getPublishDate() {
        return publishDate;
    }

    public void setPublishDate(String publishDate) {
        this.publishDate = publishDate;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
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
        return "Book{" +
                "isbn='" + isbn + '\'' +
                ", title='" + title + '\'' +
                ", catalogue='" + catalogue + '\'' +
                ", nation='" + nation + '\'' +
                ", publishDate='" + publishDate + '\'' +
                ", publisher='" + publisher + '\'' +
                ", author='" + author + '\'' +
                ", price='" + price + '\'' +
                ", desc='" + desc + '\'' +
                '}';
    }
}

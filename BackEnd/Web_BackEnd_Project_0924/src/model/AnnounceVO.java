package model;

public class AnnounceVO {
    private int number;
    private String title;
    private int view;
    private String writer;
    private String registDate;
    private String content;

    public AnnounceVO() {
    }

    public AnnounceVO(int number, String title, int view, String writer, String registDate) {
        this.number = number;
        this.title = title;
        this.view = view;
        this.writer = writer;
        this.registDate = registDate;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getView() {
        return view;
    }

    public void setView(int view) {
        this.view = view;
    }

    public String getWriter() {
        return writer;
    }

    public void setWriter(String writer) {
        this.writer = writer;
    }

    public String getRegistDate() {
        return registDate;
    }

    public void setRegistDate(String registDate) {
        this.registDate = registDate;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return "AnnounceVO{" +
                "number=" + number +
                ", title='" + title + '\'' +
                ", view=" + view +
                ", writer='" + writer + '\'' +
                ", registDate='" + registDate + '\'' +
                ", content='" + content + '\'' +
                '}';
    }
}

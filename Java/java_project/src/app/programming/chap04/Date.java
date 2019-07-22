package app.programming.chap04;

public class Date {
    private int year;
    private int month;
    private int day;

    Date() {
    }

    Date(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    String into() {
        return this.year + ", " + this.month + ", " + this.day;
    }

    public void setYear(int year) {
        if (year >= 2100 || year < 1900) {
            System.out.println("입력하신 년도는 범위를 벗어납니다.");
        } else {
            this.year = year;
        }
    }

    public int getYear() {
        return year;
    }

    public int getMonth(){
        return month;
    }
    public void setMonth(int month){
        this.month = month;
    }

    public void setDay(int day){
        this.day = day;
    }

    public int getDay(){
        return day;
    }
}
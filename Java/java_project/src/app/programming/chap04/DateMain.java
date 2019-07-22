package app.programming.chap04;

public class DateMain {
    public static void main(String[] args) {
        Date d = new Date(2019, 7, 22);

        System.out.println(d.into());

        // d.day = 32; // 접근지정자로 인해 외부 클래스에서 접근 불가
        System.out.println(d.into());
    }
}
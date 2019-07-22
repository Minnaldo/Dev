package app.programming.workshop.WS_04;

public class BookTest {
    public static void main(String[] args) {

        Book book1 = new Book("21424", "Java Pro", "김하나", "Jaen.kr", 15000, "Java 기본 문법");
        Book book2 = new Book("35355", "분석 설게", "소나무", "Jaen.kr", 30000, "SW 모델링");
        Book book3 = new Book("9791162241875", "혼자 공부하는 자바", "신용권", "한빛미디어", 24000, "프로그래밍 언어");

        Magazine magazine1 = new Magazine("35535", "Java World", "편집부", "Java.com", 7000, "첫걸음", 2018, 2);
        Magazine magazine2 = new Magazine("9771228301002", "PC사랑", "편집부", "컴퓨터생활", 9500, "컴퓨터", 2019, 6);
        Magazine magazine3 = new Magazine("9772586476005", "뉴필로소퍼 2019 7호", "뉴필로소퍼 편집부", "바다출판사", 15000, "교양", 2019, 6);

        System.out.println("************************************** 도서 목록 **************************************");
        // Book 객체 출력
        book1.toString();
        book2.toString();
        book3.toString();
        // Magazine 객체 출력
        magazine1.toString();
        magazine2.toString();
        magazine3.toString();
    }
}
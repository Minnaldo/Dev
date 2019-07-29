package chap06;

public class StringTest {
    public static void main(String[] args) {
        String str = new String("Hello");
        String str2 = new String("Hello");
        String str3 = "Hello";
        String str4 = "Hello";

        // String의 == 는 주소를 비교한다
        // 내용을 비교하고 싶다면 .equals()를 사용한다
        if (str == str2) {
            System.out.println("같다1");
        }
        if (str2 == str3) {
            System.out.println("같다2");
        }
        if (str3 == str4) {
            System.out.println("같다3");
        }
        if (str == str4) {
            System.out.println("같다4");
        }
    }
}

package chap08;

// Thread 만들기
// 1. Thread를 상속받아 run override
// 2. Runnable을 상속받는 클래스를 만들어 Thread에게 전달
// 인터페이스 또한 객체화가 가능하다   ->  객체화 후 추상메소드 오버라이드
// 
public class ThreadTest6 {
    public static void main(String[] args) {
        // 익명 내부클래스 -> 파일로는 외부클래스$숫자 로 나온다.
        // 즉 Thread변수 th는 클래스가 된다.
        Thread th = new Thread() {
            @Override
            public void run() {
                System.out.println("Thread start!");
                // 이 this는 Runnable Interface를 가리킨다.
                this.setName("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
                System.out.println(this.hashCode());
            }
        };

        System.out.println(th.hashCode());
        th.start();

        Thread th1 = new Thread(new Runnable() {

            @Override
            public void run() {
                System.out.println(this.hashCode());
            }
        });
        th1.start();
        System.out.println("outer getclass");
        System.out.println(th1.hashCode());
    }
}

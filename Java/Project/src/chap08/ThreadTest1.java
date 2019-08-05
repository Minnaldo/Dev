package chap08;

// Thread 구현 방식
// 1. Thread를 상속 -> run() 메소드 Override

public class ThreadTest1 extends Thread {

    @Override
    public void run() {
        test();
    }

    public static void main(String[] args) {
        System.out.println("Main start========================================");
//        test();7
        ThreadTest1 th = new ThreadTest1();
        ThreadTest1 th2 = new ThreadTest1();
        th.start(); // run()메소드를 실행시킨다. main과는 다른 스택에 생긴다.
        // 리턴을 받지 않는다. 다른 스택에 있으므로
        th2.start();
        System.out.println("Main end==========================================");
    }

    static void test() {
        System.out.println("test. start");
        try {
            Thread.sleep(1000 * 5);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("test. end");
    }
}

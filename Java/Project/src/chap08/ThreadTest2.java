package chap08;

// JVM이 Thread를 위한 stack 메모리를 구성하는데 시간이 필요하다
// Context Switching 때문에 스레드는 동기화가 어렵다
public class ThreadTest2 extends Thread {
    ThreadTest2(String name) {
        super(name);
    }

    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println(i + " " + Thread.currentThread());
        }
    }

    public static void main(String[] args) {
        System.out.println("Main start========================================");
        ThreadTest2 t2 = new ThreadTest2("ThreadTest1");
        t2.start();
        new ThreadTest2("ThreadTest2").start();
//        new ThreadTest2().start();
//        new ThreadTest2().start();
//        new ThreadTest2().start();
        System.out.println("Main end==========================================");
    }
}

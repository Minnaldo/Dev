package chap08;

// 스레드를 상속받지 않고 구현하는 방법

public class ThreadTest5 {
    public static void main(String[] args) {
        System.out.println("main start");
        MyRunnable r = new MyRunnable();
        Thread th = new Thread(r);
        th.start();
        System.out.println("main end");
    }
}

class MyRunnable implements Runnable {
    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                Thread.sleep(1000);
                System.out.println(i);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
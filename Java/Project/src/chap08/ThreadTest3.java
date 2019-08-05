package chap08;

public class ThreadTest3 {
    public static void main(String[] args) {
        MyThread1 t1 = new MyThread1();
        MyThread2 t2 = new MyThread2();

        t1.start();
        t2.start();
        try {
            Thread.sleep(1000 * 2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        t1.interrupt(); // run() 중인 스레드에 exception을 주어 runnable 상태로 보낸다.
        System.out.println("main end");
    }
}

class MyThread1 extends Thread {
    @Override
    public void run() {
        try {
            for (int i = 0; i < 100; i++) {
                sleep(100);
                System.out.println("MyThread1 : " + i);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class MyThread2 extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 50; i++) {
            try {
                sleep(70);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("MyThread2 : " + i);
        }
    }
}
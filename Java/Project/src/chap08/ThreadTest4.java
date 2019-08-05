package chap08;

public class ThreadTest4 {
    static int st;

    public static void main(String[] args) {
        MyThread3 t3 = new MyThread3();
        MyThread4 t4 = new MyThread4();

        t3.start();
        t4.start();

        System.out.println("main end");
    }
}

class MyThread3 extends Thread {

    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            ThreadTest4.st++;
        }

        System.out.println("Thread3 : " + ThreadTest4.st);
    }
}

class MyThread4 extends Thread {

    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            ThreadTest4.st--;
        }
        System.out.println("Thread4 : " + ThreadTest4.st);
    }
}
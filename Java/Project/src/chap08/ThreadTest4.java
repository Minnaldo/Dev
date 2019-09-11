package chap08;

public class ThreadTest4 {
    public static void main(String[] args) {
        MyThread3 th1 = new MyThread3();
        MyThread4 th2 = new MyThread4();
        th1.start();
        th2.start();
        System.out.println("Main End...........");
    }

    static Data d = new Data();
}

class Data {
    int st;
}

class MyThread3 extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            synchronized (ThreadTest4.d) {
//				ThreadTest4.d.st++;
                incre(ThreadTest4.d);
            }

        }
        System.out.println("mythread3 : " + ThreadTest4.d.st);
    }

    synchronized void incre(Data d) {
        ThreadTest4.d.st++;
    }
}

class MyThread4 extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            synchronized (ThreadTest4.d) {
//				ThreadTest4.d.st--;
                decre(ThreadTest4.d);
            }

        }
        System.out.println("mythread4 : " + ThreadTest4.d.st);
    }

    synchronized void decre(Data d) {
        ThreadTest4.d.st--;
    }
}

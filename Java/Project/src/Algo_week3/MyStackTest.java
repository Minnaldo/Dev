package Algo_week3;

import java.io.*;
import java.util.Scanner;

public class MyStackTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MyStack stack = null;

        System.out.println("1. 파일에서 읽기\n" +
                "2. 새로 생성");
        int sel = sc.nextInt();
        if (sel == 1) {
            try {
                ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("data.dat")));
                stack = (MyStack) ois.readObject();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        } else {
            stack = new MyStack(10);
        }
        boolean exitFlag = false;
        while (!exitFlag) {
            System.out.println("1. push\n" +
                    "2. pop\n" +
                    "0. 저장후 종료\n" +
                    "-1. 저장하지 않고 종료");
            sel = sc.nextInt();

            switch (sel) {
                case 1:
                    break;
                case 2:
                    break;
                case -1:
                    break;
                case 0:
                    try {
                        ObjectOutputStream oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("data.dat")));
                        oos.writeObject(stack);
                        oos.flush();
                    } catch (IOException e) {
                        e.printStackTrace();
                    } finally {
                        exitFlag = true;
                    }
                    break;
            }
        }
    }
}

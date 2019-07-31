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
                // FileInputStream은 소스(근원지)에 바로 연결되어 있다고 해서, Source Stream이라고 한다.
                // 밑의 코드는 data.dat(소스, 근원지) 에 연결되어 있는 Source Stream이다
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
                    System.out.println("삽입할 값을 입력해 주세요");
                    stack.push(sc.nextInt());
                    break;
                case 2:
                    stack.pop();
                    break;
                case -1:
                    System.out.println("프로그램을 종료합니다");
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

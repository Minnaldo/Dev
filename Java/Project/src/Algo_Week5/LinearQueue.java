package Algo_Week5;

import java.util.Scanner;

public class LinearQueue {
    public static void main(String[] args) {
        int[] queue = new int[10];
        int front = -1;
        int rear = -1;

        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1.enQueue\n" +
                    "2.deQueue\n" +
                    "3.isEmpty\n" +
                    "0.End");

            int sel = sc.nextInt();
            if (sel == 1) {
                int num = sc.nextInt();
                // insert
                // rear를 하나 늘리고 rear자리에 데이터 삽입
                queue[++rear] = num;
            } else if (sel == 2) {
                // dequeue
//                front++;
                System.out.println(queue[++front]);
            } else if (sel == 3) {
                //isempty
                if (front == rear) System.out.println("queue is empty");
                else System.out.println("queue is not empty");
            } else if (sel == 0) {
                break;
            }
        }
    }
}

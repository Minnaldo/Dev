package Algo_Week5;

import java.util.Scanner;

public class CicularQueue {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 원형큐의 초기상태는 모두 0
        int front = 0;
        int rear = 0;
        int[] queue = new int[10];


        while (true) {
            System.out.println("1. enQueue\n" +
                    "2. deQueue\n" +
                    "3. isEmpty\n" +
                    "4. isFull\n" +
                    "0. end");
            int sel = sc.nextInt();

            if (sel == 1) {
                int num = sc.nextInt();
                if (front == (rear + 1) % 10) System.out.println("Full");
                else
                    queue[++rear % 10] = num;
            } else if (sel == 2) {
                System.out.println(queue[++front % 10]);
            } else if (sel == 3) {
                if (front == rear) System.out.println("Queue is Empty");
                else System.out.println(queue[front]);
            } else if (sel == 4) {
                // 가리키는 인덱스가 한칸차이가 난다면 해당 큐는 꽉 차있는 상태이다
                // rear는 삽입부, front는 삭제부이므로, front가 rear보다 한칸 ㄷ
                if (front % 10 == (rear + 1) % 10) {
                    System.out.println("Queue is Full");
                }
            } else if (sel == 0) {
                break;
            }
        }

    }

}

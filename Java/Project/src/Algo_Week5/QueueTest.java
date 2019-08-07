package Algo_Week5;

import java.util.LinkedList;
import java.util.Queue;

public class QueueTest {
    public static void main(String[] args) {
        Queue<String> queue = new LinkedList<>();

        //삽입
        queue.add("insert");
        // front 확인만
        System.out.println(queue.peek());
        // 빼기
        System.out.println(queue.poll());
    }
}

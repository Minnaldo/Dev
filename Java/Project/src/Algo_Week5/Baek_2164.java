package Algo_Week5;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Baek_2164 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            q.add(i+1);
        }

        while (q.size() > 1) {
            q.poll();
            q.add(q.poll());
        }
        System.out.println(q.peek());

        sc.close();
    }
}
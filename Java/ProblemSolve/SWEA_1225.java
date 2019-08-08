import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.*;

public class SWEA_1225 {
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            for (int tc = 1; tc <= 10; tc++) {
                int ans = 0;
                int t = sc.nextInt();
                Queue<Integer> q = new LinkedList<>();
                // init
                for (int i = 0; i < 8; i++) {
                    int tmp = sc.nextInt();
                    q.add(tmp);
                }

                int minus = 1;

                while (true) {

                    if (q.peek() - minus <= 0) {
                        q.poll();
                        q.add(0);
                        break;
                    } else {
                        q.add(q.poll() - minus);
                        minus = ++minus == 6 ? 1 : minus;
                    }
                }

                System.out.print("#" + tc + " ");
                for (int i = 0; i < 7; i++) {
                    System.out.print(q.poll() + " ");
                }
                System.out.println(q.poll());
            }
            sc.close();

    }
}
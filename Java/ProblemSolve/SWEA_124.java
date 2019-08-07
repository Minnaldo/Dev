import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.*;

public class SWEA_124 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);

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

                System.out.println("#" + tc + " ");
                for (int i = 0; i < 7; i++) {
                    System.out.print(q.poll() + " ");
                }
                System.out.println(q.poll());
            }
            sc.close();

            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
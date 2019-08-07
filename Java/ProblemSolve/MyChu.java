import java.util.*;

public class MyChu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int candy = sc.nextInt();
        Queue<pair> q = new LinkedList<>();

        int pNum = 1;
        q.add(new pair(pNum++, 0));
        int n = candy;
        int lastMan = 0;
        int share = 0;
        while (n > 0) {
            pair p = q.poll();
            int tmpCnt = ++p.cnt;
            lastMan = p.num;
            share += tmpCnt;
            q.add(p);
            // 맨앞의 사람이 들어오고 난 후 새로운 사람
            q.add(new pair(pNum++, 0));
            n -= tmpCnt;
            System.out.println("일인당 나눠주는 사탕의 수 : " + tmpCnt);
            System.out.println("큐에 있는 사람의 수 : " + q.size());
            System.out.println("현재까지 나눠준 사탕의 수 : " + share);
        }

        System.out.println("answer : " + lastMan);

        sc.close();
    }

    public static class pair {
        int num;
        int cnt;

        pair(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }
    }
}
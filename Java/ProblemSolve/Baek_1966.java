import java.util.*;

public class Baek_1966 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();

        for (int t = 1; t <= tc; t++) {
            int ans = 1;
            int n = sc.nextInt();
            int m = sc.nextInt();
            Queue<Pair> q = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                int tmp = sc.nextInt();
                if (i == m) {
                    q.add(new Pair(tmp, true));
                } else {
                    q.add(new Pair(tmp, false));
                }
            }

            while (true) {
                boolean flag = false;

                Iterator<Pair> iter = q.iterator();
                int tmp1 = q.peek().priority;
                while (iter.hasNext()) {
                    if (tmp1 < iter.next().priority) {
                        q.add(q.poll());
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    if (q.peek().chk) {
                        break;
                    } else {
                        ans++;
                        q.poll();
                    }
                }
            }

            System.out.println(ans);
        }

        sc.close();

    }

    static class Pair {
        int priority;
        int num;
        boolean chk;

        Pair() {

        }

        Pair(int priority, boolean chk) {
            this.priority = priority;
            this.chk = chk;
        }
    }
}
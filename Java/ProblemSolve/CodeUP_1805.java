import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class CodeUP_1805 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Pair> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            arr.add(new Pair(sc.nextInt(), sc.nextInt()));
        }

        Collections.sort(arr);

        for (int i = 0; i < n; i++) {
            System.out.println(arr.get(i).num + " " + arr.get(i).gas);
        }

        sc.close();
    }

    static class Pair implements Comparable<Pair> {
        int num;
        int gas;

        Pair(int num, int gas) {
            this.num = num;
            this.gas = gas;
        }

        @Override
        public int compareTo(Pair o) {
            return this.num - o.num;
        }

    }

}
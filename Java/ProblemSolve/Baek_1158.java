import java.util.*;

public class Baek_1158 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            list.add(i);
        }

        int rmIdx = k - 1;
        while (list.size() != 1) {
            ans.add(list.get(rmIdx));
            list.remove(rmIdx);
            rmIdx += k - 1;
            rmIdx %= list.size();
        }
        ans.add(list.get(0));

        System.out.print("<");
        for (int i = 0; i < ans.size() - 1; i++) {
            System.out.print(ans.get(i) + ", ");
        }
        System.out.print(ans.get(n - 1) + ">");
    }
}
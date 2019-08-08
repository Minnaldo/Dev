import java.util.*;

public class Baek_1158_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        StringBuilder ans = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            list.add(i);
        }
        ans.append("<");
        int rmIdx = k - 1;
        while (list.size() != 1) {
            ans.append(list.get(rmIdx)+", ");
            list.remove(rmIdx);
            rmIdx += k - 1;
            rmIdx %= list.size();
        }
        ans.append(list.get(0)+">");
        System.out.println(ans);
    }
}
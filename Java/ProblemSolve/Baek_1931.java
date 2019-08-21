import java.util.*;

public class Baek_1931 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Pair[] arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(arr, (Pair o1, Pair o2) -> {
            if (o1.second < o2.second) {
                return -1;
            } else if (o1.second == o2.second) {
                if (o1.first <= o2.first)
                    return -1;
            }
            return 1;
        });

        int endTime = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].first >= endTime) {
                cnt++;
                endTime = arr[i].second;
            }
        }

        System.out.println(cnt);
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
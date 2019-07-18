import java.util.*;

public class SWEA_1933 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(1);
        for (int i = 2; i <= n; i++) {
            if (n % i == 0)
                arr.add(i);
        }

        for (int i = 0; i < arr.size() - 1; i++)
            System.out.print(arr.get(i) + " ");
        System.out.println(arr.get(arr.size() - 1));

        sc.close();
    }
}
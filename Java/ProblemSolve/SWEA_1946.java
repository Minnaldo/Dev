import java.util.Scanner;

public class SWEA_1946 {
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            for (int tc = 1; tc <= t; tc++) {
                int n = sc.nextInt();
                StringBuilder sb = new StringBuilder();
                StringBuilder ans = new StringBuilder();

                for (int i = 0; i < n; i++) {
                    char ch = sc.next().charAt(0);
                    int mul = Integer.parseInt(sc.next());

                    for (int j = 0; j < mul; j++) {
                        ans.append(ch);
                    }
                }

                System.out.print("#" + tc);
                for (int i = 0; i < ans.length(); i++) {
                    if (i % 10 == 0) {
                        System.out.println();
                    }
                    System.out.print(ans.charAt(i));
                }
                System.out.println();

            }
            sc.close();

    }
}
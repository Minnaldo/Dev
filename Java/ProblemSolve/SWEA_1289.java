import java.util.Scanner;

public class SWEA_1289 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int ans = 0;
            StringBuilder str = new StringBuilder(sc.next());
            int[] before = new int[str.length()];
            int[] fin = new int[str.length()];

            // 초기 메모리 상태
            for (int i = 0; i < str.length(); i++) {
                before[i] = 0;
                fin[i] = Character.digit(str.charAt(i), 10);
            }

            while (true) {
                int idx = 0, val = 0;
                boolean flag = false;
                for (int i = 0; i < str.length(); i++) {
                    if (fin[i] != before[i]) {
                        idx = i;
                        val = fin[i];
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    break;
                }

                for (int i = idx; i < str.length(); i++) {
                    before[i] = val;
                }

                ans++;
            }

            System.out.println("#" + tc + " " + ans);
        }
        sc.close();
    }
}
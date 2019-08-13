import java.io.FileInputStream;
import java.util.*;

/**
 *  TODO
 */

public class SWEA_1232 {

    static int n;
    static Stack<Integer> oper;
    static StringBuilder sb;
    static boolean[] visit;
    static String[] arr;

    // idx <= current index
    public static void recur(int idx) {
        int chidx = idx * 2;
        if (chidx <= n && !visit[chidx]) {
            recur(chidx);
        }
        if (chidx + 1 <= n && !visit[chidx + 1]) {
            recur(chidx + 1);
            // 문자일 때
            sb.append(arr[idx] );
            // if (isStringtoInteger(arr[idx]))
            // oper.add(Integer.parseInt(arr[idx]));
            // else
            // oper.add(calc(arr[idx]));
            visit[idx] = true;
        } else {
            // 숫자일 때
            sb.append(arr[idx] );
            // if (isStringtoInteger(arr[idx]))
            // oper.add(Integer.parseInt(arr[idx]));
            // else
            // oper.add(calc(arr[idx]));
            visit[idx] = true;
        }
    }

    public static int calc(String str) {
        int af = oper.pop(), bf = oper.pop();
        int ret = 0;
        switch (str.charAt(0)) {
        case '-':
            ret = bf - af;
            break;
        case '+':
            ret = bf + af;
            break;
        case '/':
            ret = bf / af;
            break;
        case '*':
            ret = bf * af;
            break;
        }
        return ret;
    }

    public static boolean isStringtoInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            for (int tc = 1; tc <= 5; tc++) {
                n = sc.nextInt();
                visit = new boolean[n + 1];
                arr = new String[n + 1];

                sc.nextLine();
                for (int i = 1; i <= n; i++) {
                    String[] input = sc.nextLine().split(" ");
                    arr[Integer.parseInt(input[0])] = input[1];
                }
                oper = new Stack<>();
                sb = new StringBuilder();
                recur(1);

                System.out.print("#" + tc + " ");
                System.out.println(sb.toString());

                // int ans = oper.pop();
                // System.out.println("#" + tc + " " + ans);
            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
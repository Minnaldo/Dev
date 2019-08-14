import java.io.FileInputStream;
import java.util.*;

/**
 * TODO
 */

public class SWEA_1232 {

    static int n;
    static Stack<Double> oper;
    static StringBuilder sb;
    static String[] arr;

    // idx <= current index
    public static void recur(int idx) {
        if (idx > n)
            return;

        // 왼쪽
        recur(idx * 2);
        // 오른쪽
        recur(idx * 2 + 1);
        // 판단 후 그에 맞는 연산
        sb.append(arr[idx]).append(" ");
    }

    public static void calc(String str) {
        double af = oper.pop(), bf = oper.pop();
        double ret = 0;
        switch (str) {
        case "-":
            ret = bf - af;
            break;
        case "+":
            ret = bf + af;
            break;
        case "/":
            ret = bf / af;
            break;
        case "*":
            ret = bf * af;
            break;
        default:
            System.out.println("error");
        }
        oper.add(ret);
    }

    public static boolean isStringtoInteger(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            for (int tc = 1; tc <= 10; tc++) {
                n = sc.nextInt();
                arr = new String[n + 1];

                sc.nextLine();
                for (int i = 1; i <= n; i++) {
                    String[] input = sc.nextLine().split(" ");
                    arr[Integer.parseInt(input[0])] = input[1];
                }
                oper = new Stack<>();
                sb = new StringBuilder();
                recur(1);
                System.out.println(sb.toString());
                // StringTokenizer st = new StringTokenizer(sb.toString());
                // while (st.hasMoreTokens()) {
                // String tmp = st.nextToken();
                // // System.out.print(tmp + " ");
                // if (isStringtoInteger(tmp)) {
                // // 피연산자 일 때
                // oper.add(Double.parseDouble(tmp));
                // } else if (!isStringtoInteger(tmp)) {
                // // 연산자 일 때
                // calc(tmp);
                // }
                // }

                int ans = 0;
                // int ans = (int) Math.ceil(oper.pop());
                System.out.println("#" + tc + " " + ans);
            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.util.*;
import java.io.*;

public class SWEA_1223 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int tc = 1; tc <= 1; tc++) {
            int ans = 0;

            int n = sc.nextInt();
            String str = sc.next();
            Stack<Character> s = new Stack<>();
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (Character.isDigit(c)) {
                    sb.append(c);
                } else {
                    if (c == '+') {
                        while (!s.isEmpty()) {
                            sb.append(s.pop());
                        }
                        s.push(c);
                    } else {
                        while (!s.isEmpty() && s.peek() != '+') {
                            sb.append(s.pop());
                        }
                        s.push(c);
                    }
                }
            }

            // ! 마지막 문자열에 남은 연산자를 모두 비워낸다.
            // ! 비워내지 않으면 후위식은 올바른 식이 될 수 없다.
            while (!s.empty()) {
                sb.append(s.pop());
            }

            Stack<Integer> ss = new Stack<>();
            for (int i = 0; i < sb.length(); i++) {
                char c = sb.charAt(i);
                if (Character.isDigit(c)) {
                    ss.push(c - '0');
                } else {
                    int bef = ss.pop();
                    int af = ss.pop();

                    switch (c) {
                    case '+':
                        ss.push(af + bef);
                        break;
                    case '*':
                        ss.push(af * bef);
                        break;
                    }
                }
            }

            ans = ss.pop();
            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}
import java.util.*;
import java.io.*;

public class SWEA_1224 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int tc = 1; tc <= 10; tc++) {
            int ans = 0;

            int n = sc.nextInt();
            String str = sc.next();
            Stack<Character> s = new Stack<>();
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);

                if (Character.isDigit(c)) {
                    // 현재 c가 숫자일때
                    sb.append(c);
                } else {
                    // c 가 연산자 및 괄호 일때
                    if (c == '(') {
                        s.push(c);
                    } else if (c == '*') {
                        while (!s.empty() && s.peek() != '+' && s.peek() != '(') {
                            sb.append(s.pop());
                        }
                        s.push(c);
                    } else if (c == '+') {
                        while (!s.empty() && s.peek() != '(') {
                            sb.append(s.pop());
                        }
                        s.push(c);

                    } else if (c == ')') {
                        // c가 닫는괄호일때
                        while (!s.empty() && s.peek() != '(') {
                            sb.append(s.pop());
                        }

                        if (!s.empty() && s.peek() == '(') {
                            s.pop();
                        }
                    }
                }
            }
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

/**
 *  문자열을 탐색하면서 피연산자는 스택에 담는다.
 *  연산자를 만나면 스택에서 2개를 po해서 연산자와 연산 후 스택에 담는다.
 *  마지막 스택에 남아있는 값이 결과이다.
 */

import java.util.*;

public class Stack_Calc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.next();
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c - '0' >= 0 && c - '0' <= 9) {
                s.push(c - '0');
            } else {
                int bef = s.pop();
                int af = s.pop();
                switch (c) {
                case '+':
                    s.push(af + bef);
                    break;
                case '-':
                    s.push(af - bef);
                    break;
                case '*':
                    s.push(af * bef);
                    break;
                case '/':
                    s.push(af / bef);
                    break;
                }
            }
        }
        System.out.println("결과는 : " + s.pop());
        // for (int i = 0; i < str.length(); i++) {
        // char c = str.charAt(i);
        // if (Character.isDigit(c)) {
        // s.push(Character.digit(c, 10));
        // } else {
        // int bef = s.pop();
        // int af = s.pop();

        // switch (c) {
        // case '+':
        // s.push(af + bef);
        // break;
        // case '-':
        // s.push(af - bef);
        // break;
        // case '*':
        // s.push(af * bef);
        // break;
        // case '/':
        // s.push(af / bef);
        // break;
        // }
        // }
        // }

        sc.close();
    }
}
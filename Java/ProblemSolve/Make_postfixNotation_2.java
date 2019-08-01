import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Make_postfixNotation_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Character> s = new Stack<>();
        ArrayList<Character> arr = new ArrayList<>();

        String str = sc.next();

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);

            if (Character.isDigit(c)) {
                // 현재 c가 숫자일때
                arr.add(c);
            } else {
                // c 가 연산자 및 괄호 일때
                if (c == '(') {
                    s.push(c);
                } else if (c == '*' || c == '/') {
                    if (!s.empty())
                        if (s.peek() != '+' || s.peek() != '-') {
                            arr.add(s.pop());
                        }
                    s.push(c);
                } else if (c == '+' || c == '-') {
                    while (s.peek() != '(') {
                        arr.add(s.pop());
                    }
                } else {
                    // c가 닫는괄호일때
                    while (s.peek() != '(') {
                        arr.add(s.pop());
                    }
                    s.pop(); // 여는괄호 제거
                }
            }

            while (!s.empty()) {
                arr.add(s.pop());
            }

        }
        System.out.println(s.toString());
        sc.close();
    }
}
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Make_postfixNotation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        Stack<Character> s = new Stack<>();
        ArrayList<Character> arr = new ArrayList<>();

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (Character.isDigit(c)) {
                arr.add(c);
            } else {
                if (c == '+') {
                    while (!s.isEmpty()) {
                        arr.add(s.pop());
                    }
                    s.push(c);
                } else if (c == '*') {
                    if (s.peek() == '+') {
                        s.push(c);
                    } else {
                        arr.add(s.pop());
                        s.push(c);
                    }
                }
            }
        }

        System.out.println(arr.toString());

        sc.close();
    }
}
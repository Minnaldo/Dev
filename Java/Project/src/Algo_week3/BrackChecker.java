package Algo_week3;

import java.util.Scanner;
import java.util.Stack;

public class BrackChecker {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        Stack<Character> s = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                s.push('(');
            } else {
                if (!s.isEmpty()) {
                    s.pop();
                } else {
                    System.out.println("Error Occured\nBracket not matching\nStack is empty");
                    return;
                }
            }
        }
        if (s.isEmpty())
            System.out.println("알맞는 괄호 갯수가 들어 있습니다.");
        else
            System.out.println("Error Occured\nBracket not matching\n" +
                    "Open bracket more than Close bracket");
    }
}

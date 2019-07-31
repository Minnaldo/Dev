import java.util.*;
import java.io.*;

public class SWEA_1218 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            for (int tc = 1; tc <= 10; tc++) {
                int ans = 1;
                Stack<Character> s = new Stack<>();
                int size = sc.nextInt();
                String str = sc.next();

                for (int i = 0; i < size; i++) {
                    char c = str.charAt(i);
                    if (c == '(' || c == '{' || c == '<' || c == '[') {
                        s.push(c);
                    } else {
                        if (c == ')') {
                            if (s.peek() == '(') {
                                s.pop();
                            } else {
                                ans = 0;
                                break;
                            }
                        } else if (c == '}') {
                            if (s.peek() == '{') {
                                s.pop();
                            } else {
                                ans = 0;
                                break;
                            }
                        } else if (c == '>') {
                            if (s.peek() == '<') {
                                s.pop();
                            } else {
                                ans = 0;
                                break;
                            }
                        } else {
                            if (c == ']') {
                                s.pop();
                            } else {
                                ans = 0;
                                break;
                            }
                        }

                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
            sc.close();
            fis.close();
        } catch (

        Exception e) {
            e.printStackTrace();
        }
    }
}
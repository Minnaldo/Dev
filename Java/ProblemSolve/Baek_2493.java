
// 왼쪽으로만 레이저를 발사

import java.io.*;
import java.util.*;

public class Baek_2493 {

    public static class pair {
        int x;
        int y;

        pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            String s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);
            int n = Integer.parseInt(st.nextToken()); // n 은 최대 50만

            st = new StringTokenizer(br.readLine());
            Stack<pair> stack = new Stack<>();
            ArrayList<Integer> ans = new ArrayList<>();
            // input
            for (int i = 0; i < n; i++) {
                int tmp = Integer.parseInt(st.nextToken());

                while (!stack.empty()) {
                    if (stack.peek().y > tmp) {
                        System.out.print(stack.pop().x + " ");
                        break;
                    }
                    stack.pop();
                }

                if (stack.empty())
                    System.out.print("0 ");

                stack.push(new pair(i, tmp));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
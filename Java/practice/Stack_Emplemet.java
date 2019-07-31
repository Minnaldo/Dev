import java.util.Scanner;

public class Stack_Emplemet {

    static int idx = -1;
    static int[] stack = new int[5];

    public static void push(int a) {
        if (idx < 4) {
            stack[++idx] = a;
        } else {
            System.out.println("스택에 빈공간이 없습니다.");
        }
    }

    public static int pop() {
        if (idx >= 0) {
            stack[idx] = 0;
            return stack[idx--];
        } else if (idx == -1) {
            System.out.println("스택에 데이터가 없습니다.");
        }
        return 0;
    }

    public static boolean isEmpty() {
        if (idx == -1) {
            System.out.println("스택이 비어있습니다");
            return true;
        } else
            return false;
    }

    public static int peek() {
        return stack[idx--];
    }

    public static int top() {
        return stack[idx];
    }

    public static void printStack() {
        for (int aa : stack) {
            if (aa > 0)
                System.out.print(aa + " ");
        }
        System.out.println();
    }

    public static void printFunc() {
        System.out.println("1. push, 2. pop, 3. 내용 출력, 0. 종료");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        boolean exitFlag = false;
        while (!exitFlag) {
            printFunc();
            switch (sc.nextInt()) {
            case 1:
                System.out.println("저장할 값을 입력해 주세요");
                push(sc.nextInt());
                break;
            case 2:
                System.out.println(top() + "을 스택에서 지웠습니다");
                pop();
                break;
            case 3:
                printStack();
                break;
            case 0:
                System.out.println("종료합니다");
                exitFlag = true;
                break;
            }
        }
        sc.close();
    }
}
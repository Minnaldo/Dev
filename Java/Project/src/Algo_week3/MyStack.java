package Algo_week3;

import java.io.Serializable;

public class MyStack implements Serializable {
    private int[] stack;
    private int top;
    private int size;

    MyStack(int size) {
        stack = new int[size];
        top = -1;
        this.size = size;
    }

    public void push(int data) {
        if (top >= stack.length - 1) {
            throw new MyStackOverflowException();
        }
        stack[++top] = data;
    }

    public int pop() {
        if (top == -1) {
            throw new MyStackEmptyException();
        }
        return stack[top--];
    }
}

class MyStackOverflowException extends RuntimeException {

}

class MyStackEmptyException extends RuntimeException {
}
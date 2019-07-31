public class MyStack {
    private int[] stack;
    private int top;
    private int size;

    MyStack(int size){
        stack = new int[size];
        top = -1;
        this.size = size;
    }

    public void push(int data){
        if(top < size-1)
        stack[top] = data;
    }
    public int pop(){
        if()
    }
}

class MyStackOverflowException extends RuntimeException{

}
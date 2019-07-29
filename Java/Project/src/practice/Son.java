package practice;

public class Son extends Mother implements Father{
    public static void main(String[] args) {
        Mother s = new Son();
        s.show();
    }
}

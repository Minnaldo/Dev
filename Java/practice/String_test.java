public class String_test {
    public static void main(String[] args) {
        if ("" + 1 instanceof String) {
            System.out.println("this is String");
        } else {
            System.out.println("this is not String");
        }
        int aa = 1;
        if (Integer.class.isInstance(aa)) {
            System.out.println("this is Integer");
        } else {
            System.out.println("this is not Integer");
        }
    }
}
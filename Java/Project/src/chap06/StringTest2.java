package chap06;

public class StringTest2 {
    public static void main(String[] args) {
        // String builder가 String변수에 '+'가 매우 빠르다
        String str = "Hello";
        StringBuilder sb = new StringBuilder(str);
        sb.append("a");
        System.out.println(sb.toString());

        double start = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) {
            str += "s";
            str += "t";
            str += "r";
            str += "i";
            str += "n";
            str += "g";
        }
        double end = System.currentTimeMillis();

        System.out.println((end - start) + " ms");

        start = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) {
            sb.append("s");
            sb.append("t");
            sb.append("r");
            sb.append("i");
            sb.append("n");
            sb.append("g");
        }
        end = System.currentTimeMillis();
        System.out.println((end - start) + " ms");
    }
}

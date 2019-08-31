public class DbugTest {
    public static void main(String[] args) {
        Sacnner sc = new Scanner(System.in);

        System.out.println(sum(sc.nextInt(), sc.nextInt()));
    }

    static int sum(int a, int b) {
        return a + b;
    }
}
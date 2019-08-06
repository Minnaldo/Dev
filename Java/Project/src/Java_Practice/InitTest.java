package Java_Practice;

public class InitTest {
    public static void main(String[] args) {

        long start = System.nanoTime();
        for (int i = 0; i < 100000; i++) {
            int[][] arr = new int[10000][10000];
        }
        System.out.println("Processing Time : " + (double) (System.nanoTime() - start) / 1000000000 + " sec");


        long start2 = System.nanoTime();
        int[][] arr2 = new int[10000][10000];
        for (int a = 0; a < 100000; a++) {
            for (int i = 0; i < 10000; i++) {
                for (int j = 0; j < 10000; j++) {
                    arr2[i][j] = 0;
                }
            }
        }
        System.out.println("Processing Time : " + (double) (System.nanoTime() - start2) / 1000000000 + " sec");
    }
}

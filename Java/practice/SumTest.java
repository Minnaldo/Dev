import java.io.*;
import java.util.*;

public class SumTest {
    public static void main(String[] args) {

        long[] arr = new long[10001];

        try (FileInputStream fis = new FileInputStream("Sum_test.txt")) {
            Scanner sc = new Scanner(fis);
            long start = System.currentTimeMillis();

            for (int i = 1; i <= 10000; i++) {
                arr[i] = arr[i - 1] + sc.nextInt();
            }

            long sum = 0;
            for (int i = 1; i <= 10000; i++) {
                sum += arr[10000] - arr[i];
            }

            long end = System.currentTimeMillis();
            System.out.println((end - start) + " ms\n");

            System.out.println(sum);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
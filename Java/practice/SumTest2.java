import java.util.*;
import java.io.*;

public class SumTest2 {
    public static void main(String[] args) {

        long[] arr;

        // try (FileInputStream fis = new FileInputStream("Sum_test.txt")) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        arr = new long[input + 1];

        long start = System.nanoTime();

        for (int i = 1; i <= input; i++) {
            arr[i] = arr[i - 1] + i;
        }

        long sum = 0;
        for (int i = 1; i <= input; i++) {
            for (int j = i; j <= input; j++) {
                sum += arr[j];
            }
        }

        long end = System.nanoTime();
        System.out.println((end - start) / 1000000.0 + " ms\n");

        System.out.println(sum);

        // } catch (Exception e) {
        // e.printStackTrace();
        // }
    }
}
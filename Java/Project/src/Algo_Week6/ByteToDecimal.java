package Algo_Week6;

import java.util.Scanner;

public class ByteToDecimal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int n = str.length();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Character.digit(str.charAt(i), 10);
        }

        for (int i = 0; i < n; i += 7) {
            int sum = 0;
            for (int j = i + 6; j >= i; j--) {
                sum += arr[j] * Math.pow(2, j%7);
            }
            System.out.print(sum + " ");
        }
        System.out.println();
        int start = 0;
        int end = 7;
        while (end <= str.length()) {
            String binary = str.substring(start, end);

            int num = 0;
            for (int i = 0; i < 7; i++) {
                num += (binary.charAt(7 - 1 - i) - '0') * (1 << i);
            }
            System.out.print(num + " ");

            start += 7;
            end += 7;
        }
    }
}
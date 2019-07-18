package com.ssafy.algo;

import java.util.*;

public class DigitTest1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = 0;
		int[] arr = new int[10];

		while (true) {
			num = sc.nextInt();
			if (num == 0) {
				break;
			}
			arr[num / 10]++;
		}

		
		for (int i = 0; i < 10; i++) {
			if (arr[i] != 0) {
				System.out.println(i + " : " + arr[i] + "°³");
			}
		}

		sc.close();
	}
}

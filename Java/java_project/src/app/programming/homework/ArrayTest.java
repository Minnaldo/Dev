package app.programming.homework;

import java.util.*;

public class ArrayTest {

	static int[] arr;

	public static void print() {
		for (int i = 0; i < arr.length - 1; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println(arr[arr.length - 1]);
	}

	public static void total() {
		int total = 0;
		for (int val : arr) {
			total += val;
		}
		System.out.println(total);
	}

	public static void average() {
		int avg = 0, sum = 0;
		for (int val : arr) {
			sum += val;
		}
		avg = sum / arr.length;
		System.out.println(avg);
	}

	public static void minimum() {
		int min = 2130000000;
		for (int val : arr) {
			min = min < val ? min : val;
		}
		System.out.println(min);
	}

	public static void main(String[] args) {
		System.out.println("�Է�");
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();

		String[] strArr = str.split(" ");
		arr = new int[strArr.length];
		int idx = 0;
		for (String val : strArr) {
			arr[idx] = Integer.parseInt(val); // string to int
			idx++;
		}

		print();
		System.out.print("�迭�� �� : ");
		total();
		System.out.print("�迭�� ��� : ");
		average();
		System.out.print("�迭�� �ּҰ� : ");
		minimum();

		sc.close();
	}
}

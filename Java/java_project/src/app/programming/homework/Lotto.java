package app.programming.homework;

import java.util.*;

public class Lotto {

	public static void main(String[] args) {

		int[] arr = new int[6];
		System.out.println("�ζ��� �ְ����ڸ� �Է��ϼ���");
		Scanner sc = new Scanner(System.in);
		int max = sc.nextInt();
		int idx = 0;

		while (idx < 6) {
			// ���� �ܰ迡�� ���� ��
			int val = (int) (Math.random() * 100) % max + 1;

			boolean flag = false;
			for (int i = 0; i < idx; i++) {
				if (arr[i] == val) {
					flag = true;
					break;
				}
			}

			if (!flag) {
				arr[idx] = val;
				idx++;
			}
		}

		Arrays.sort(arr);

		for (int val : arr) {
			System.out.print(val+" ");
		}

		sc.close();
	}

}

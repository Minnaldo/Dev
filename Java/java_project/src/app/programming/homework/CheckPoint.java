package edu.ssafy.chap01;

import java.util.Scanner;

public class CheckPoint {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int height = sc.nextInt();
		int weight = sc.nextInt();
		int ans = weight + 100 - height;
		System.out.println("�񸸼�ġ�� " + ans + "�Դϴ�.");

		if (ans > 0) {
			System.out.println("����� ���̱���");
		}
		
		sc.close();
	}
}

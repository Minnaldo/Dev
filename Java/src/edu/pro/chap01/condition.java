package edu.ssafy.chap01;

import java.util.*;

public class condition {
	public static void main(String[] args) {

		boolean bool = false; // boolean�� �⺻���� false

		int a = 3;
		// if
//		if (a < 4 /* ���� */) {
//			System.out.println("A");
//		}
//		else if(a<7){
//			System.out.println("B");
//		}else {
//			System.out.println("C");
//		}

		// switch
		// ������ ����񱳸� ����
		// �Ǽ� ��� �Ұ�, ����, �Ǽ�, ����, ���ڿ� ��� ����
		Scanner sc = new Scanner(System.in);
//		a = sc.nextInt();
		String b = sc.next();
		System.out.println(b);
		switch (a/10) {
		case 10:
		case 9:
			System.out.println("A");
			break;
		case 8:
			System.out.println("B");
			break;
		case 7:
			System.out.println("C");
			break;
		case 6:
			System.out.println("D");
			break;
		default:
			System.out.println("F");
			break;
		}
		sc.close();
	}
}

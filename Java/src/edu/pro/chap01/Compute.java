package edu.ssafy.chap01;

import java.util.Scanner;

public class Compute {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		System.out.println("°ö="+(a*b));
		System.out.println("¸ò="+(a/b));
		
		sc.close();
	}
	
}

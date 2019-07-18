package edu.ssafy.chap01;

import java.util.*;

public class LoopTest {

	public static void main(String[] args) {
		Random r = new Random();

//		// while
//		int condition = 0;
//		while (condition < 6) {
//			int val1 = r.nextInt(100) % 45 + 1;
//			System.out.println(val1);
//			condition++;
//		}
//
//		// do~while
//		do {
//			int val1 = r.nextInt(100) % 45 + 1;
//			System.out.println(val1);
//			condition++;
//		} while (condition < 610);

		// for
		// a is local variable
		for (int a = 4; a >= 0; a--) {
//			int val1 = r.nextInt(100) % 45 + 1;
//			System.out.println(val1);
			System.out.println(a);
		}

//		int val1 = r.nextInt(100) % 45 + 1;
//		System.out.println(val1);
	}
}

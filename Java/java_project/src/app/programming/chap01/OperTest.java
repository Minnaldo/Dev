package edu.ssafy.chap01;

import java.util.*;

public class OperTest {
	public static void main(String[] args) {
		int sum=0, oper1 = 15, oper2= 12;
		
		sum = oper1 + oper2;
		int min = oper1 - oper2;
		int cro = oper1 * oper2;
		float div= oper1/oper2;
		int mod = oper1%oper2;
		
		System.out.println(sum);
		System.out.println(min);
		System.out.println(cro);
		System.out.println(div);
		System.out.println(mod);
		
		Random r = new Random();
//		int val = r.nextInt(45);	// 0~45
		int val = r.nextInt(100)%45+1;	// 1~45
		
		System.out.println(val);
	}
}

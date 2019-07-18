package edu.ssafy.chap01;

public class LoopTest2 {

	public static void main(String[] args) {
		for (int i = 2; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				System.out.println(i + " x " + j + " = " + i * j);
			}
		}
		
		System.out.println("----------------------------------------------------------------------");
		
		for(int i = 4; i>0; i--)
		{
			for(int j = i; j>0; j--)
			{
				System.out.print("*");
			}
			System.out.println();
		}
		
	}

}

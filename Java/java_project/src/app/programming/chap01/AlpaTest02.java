package edu.ssafy.chap01;

public class AlpaTest02 {
	public static void main(String[] args) {
		int num = 65;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4 - i; j++) {
				System.out.print("  ");
			}
			for (int j = 4 - i; j < 5; j++) {
				if(j < 4)
					System.out.print((char) num + " ");
				else
					System.out.println((char)num);
				num++;
			}
		}
	}
}

package app.programming.chap01;

public class AlpaTest01 {
	public static void main(String[] args) {
		int num = 65;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < i+1; j++) {
				System.out.print((char)num+" ");
				num++;
			}
			System.out.println();
		}
	}
}

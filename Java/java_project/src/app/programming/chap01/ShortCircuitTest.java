package app.programming.chap01;

public class ShortCircuitTest {

	public static void main(String[] args) {
		int x = 0;
		int y = 0;

		// bit and operator
		// 비트 연산자는 앞/뒤 condition 모두 실행된다 ==> x값이 증가함
		// 앞쪽이 참이면 뒤쪽 condition 실행, 앞쪽이 거짓이면 뒤쪽 condition 실행 안함
		// 이를 이용해 condition을 통해 뒤쪽에 복잡한 함수를 실행하도록 할 수 있음
		if ((2 > 5) & (x++ > y)) {
			y++;
		}

		System.out.println("x = " + x + ",y = " + y);

		x = 0;
		y = 0;

		// logical and operator
		// 앞쪽이 거짓이니 뒤쪽의 조건은 실행안하고 넘어간다
		if((2>5)&&(x++>y))
		{
			y++;
		}

		System.out.println("x = " + x + ",y = " + y);
	}

}

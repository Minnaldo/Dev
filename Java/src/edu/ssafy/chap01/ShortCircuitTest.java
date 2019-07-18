package edu.ssafy.chap01;

public class ShortCircuitTest {

	public static void main(String[] args) {
		int x = 0;
		int y = 0;

		// bit and operator
		// ��Ʈ �����ڴ� ��/�� condition ��� ����ȴ� ==> x���� ������
		// ������ ���̸� ���� condition ����, ������ �����̸� ���� condition ���� ����
		// �̸� �̿��� condition�� ���� ���ʿ� ������ �Լ��� �����ϵ��� �� �� ����
		if ((2 > 5) & (x++ > y)) {
			y++;
		}

		System.out.println("x = " + x + ",y = " + y);

		x = 0;
		y = 0;
		
		// logical and operator
		// ������ �����̴� ������ ������ ������ϰ� �Ѿ��
		if((2>5)&&(x++>y))
		{
			y++;
		}
		
		System.out.println("x = " + x + ",y = " + y);
	}

}

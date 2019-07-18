package edu.ssafy.chap02;

public class ArrayTest {
	// Array
	// ���� : ���� ������ Ÿ���� ������ ����(�ڷᱸ���� ���� ���� �˻��� �����ϴ�)
	// Ư¡ : ����� ���ÿ� ũ�Ⱑ �����Ǿ����� �ѹ� ������ ũ��� ������ �� ����
	// �迭�� �����ϸ� Ÿ�Կ� ���� �⺻������ �ʱ�ȭ
	// ���� = 0, �Ǽ� = 0.0, ���� = \u0000, �� = false, ����(reference) : null
	public static void main(String[] args) {
		int kuk = 100, math = 80, eng = 50;
		int sum = kuk + math + eng;
		System.out.println(sum);
		System.out.println("=================");

		int[] jumsu = new int[3]; // int type�� �迭 ����
		jumsu[0] = 100;
		jumsu[1] = 80;
		jumsu[2] = 50;

		sum = jumsu[0] + jumsu[1] + jumsu[2];
		System.out.print("use the array  :  ");
		System.out.println(sum);

		float[] arr1 = new float[3];
		System.out.println(arr1[0]);
		char[] arr2 = new char[4];
		System.out.println(arr2[0]);
		boolean[] arr3 = new boolean[5];
		System.out.println(arr3[0]);

		System.out.println(arr1.length);

		testFunc(jumsu);
		System.out.println("main kuk : " + jumsu[0]);

		Member m = new Member(); // Ŭ���� ��ü(�ν��Ͻ�) ����
		Member m2 = new Member();
		Member m3 = new Member();
		// marr �� �ּҰ��� ���� �ǹǷ�, 4Bytes ������ ���´�
		Member[] marr = new Member[3]; // Member type�� �迭 ����
		marr[0] = m;	// marr[0] ���� m�� �ּҰ� ���� �ȴ�. (���� ��ü�� ���� �ʿ䰡 ����)
		marr[1] = new Member();
		marr[2] = new Member();
	}

	// �迭�� call by reference �̹Ƿ� �Լ� ���� ��ȭ�� ������ ������ �ش�
	public static void testFunc(int[] arr) {
		System.out.println("testFunc kuk : " + --arr[0]);
		System.out.println(arr.length); // ��ü ���·� �Ѿ���Ƿ�, ��ü�� ��� �Լ��� ����� �� �ִ�.
	}

}

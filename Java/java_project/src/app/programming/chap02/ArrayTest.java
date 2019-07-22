package app.programming.chap02;

public class ArrayTest {
	// Array
	// 정의 : 같은 데이터 타입의 순서적 나열(자료구조중 가장 빠른 검색이 가능하다)
	// 특징 : 선언과 동시에 크기가 결정되어지며 한번 결정된 크기는 변경할 수 없다
	// 배열은 생성하면 타입에 따라 기본값으로 초기화
	// 정수 = 0, 실수 = 0.0, 문자 = \u0000, 논리 = false, 참조(reference) : null
	public static void main(String[] args) {
		int kuk = 100, math = 80, eng = 50;
		int sum = kuk + math + eng;
		System.out.println(sum);
		System.out.println("=================");

		int[] jumsu = new int[3]; // int type의 배열 선언
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

		Member m = new Member(); // 클래스 객체(인스턴스) 생성
		Member m2 = new Member();
		Member m3 = new Member();
		// marr 은 주소값을 갖게 되므로, 4Bytes 공간을 갖는다
		Member[] marr = new Member[3]; // Member type의 배열 선언
		marr[0] = m;	// marr[0] 에는 m의 주소가 들어가게 된다. (굳이 객체를 넣을 필요가 없다)
		marr[1] = new Member();
		marr[2] = new Member();
	}

	// 배열은 call by reference 이므로 함수 내의 변화가 원본에 영향을 준다
	public static void testFunc(int[] arr) {
		System.out.println("testFunc kuk : " + --arr[0]);
		System.out.println(arr.length); // 객체 형태로 넘어오므로, 객체의 멤버 함수를 사용할 수 있다.
	}

}

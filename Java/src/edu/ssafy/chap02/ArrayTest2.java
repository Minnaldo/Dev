package edu.ssafy.chap02;

public class ArrayTest2 {
	public static void main(String[] args) {
		int[] arr = { 1, 3, 5, 7 }; // 배열의 선언과 초기화
//		System.out.println(arr.length);
//		System.out.println(arr[2]);

		for (int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]); // i 는 index 값
		}

		int[] arr2 = new int[arr.length + 1]; // 5개 배열 선언
		
		System.arraycopy(arr, 0, arr2, 0, arr.length);	// array 깊은 복사
		
		System.out.println();
//		for (int i = 0; i < arr.length; i++) {
//			System.out.println(arr2[i]);
//		}
		
		for(int val : arr2)
		{
			System.out.println(val);
		}
	}
}

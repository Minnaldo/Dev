package edu.ssafy.chap02;

public class ArrayTest2 {
	public static void main(String[] args) {
		int[] arr = { 1, 3, 5, 7 }; // �迭�� ����� �ʱ�ȭ
//		System.out.println(arr.length);
//		System.out.println(arr[2]);

		for (int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]); // i �� index ��
		}

		int[] arr2 = new int[arr.length + 1]; // 5�� �迭 ����
		
		System.arraycopy(arr, 0, arr2, 0, arr.length);	// array ���� ����
		
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

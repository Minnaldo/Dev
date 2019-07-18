package edu.ssafy.chap02;

public class ArrayTest3 {
	public static void main(String[] args) {
		int[][] arr = new int[2][3];

		arr[0][0] = 1;
		arr[0][1] = 13;
		arr[0][2] = 23;
		arr[1][0] = 33;
		arr[1][1] = 44;
		arr[1][2] = 55;
		
		for(int[] aa : arr)
		{
			for(int val : aa)
			{
				System.out.print(val+" ");
			}
			System.out.println();
		}
		
		System.out.println("==========================");
		
		// 자바의 다차원배열에서 기본 형식이 포인터 배열
		int[][] arr2 = new int[3][];	// arr2 는 첫번째 칸만 가리키기 때문에, 뒷 배열은 나중에 선언하여도 된다
		arr2[0] = new int[2];
		arr2[1] = new int[10];
		arr2[2] = new int[11];
		
		int[][] arr3 = {{3,5,7},{12,25,66}};
		
		for(int i = 0; i< arr3.length; i++)
		{
			for(int j =0; j<arr3[0].length; j++)
			{
				System.out.println(arr3[i][j]);
			}
		}
		
		
		int [][] k = {{1,2,3,4,5,6,7,8},{2,3,4,5},{6,8}};
		
		for(int i = 0; i<k.length; i++)	// row 탐색
		{
			for(int j = 0; j<k[i].length; j++)	// colum 탐색
			{
				System.out.print(k[i][j]+" ");	
			}
			System.out.println();
		}

	}
}
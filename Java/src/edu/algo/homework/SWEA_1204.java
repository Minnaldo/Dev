/**	최빈수 구하기
 *
 */
import java.util.Scanner;

public class SWEA_1204 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t= sc.nextInt();

		for(int tc = 1; tc<=t; tc++)
		{
			int ans = 0;
			int proNum = sc.nextInt();
			int[] arr = new int[101];	// 0000000000000

			for(int i = 0; i<1000; i++)
				arr[sc.nextInt()]++;

			for(int i = 1; i<arr.length; i++)
				ans = (arr[ans] > arr[i]) ? ans : i;

			System.out.println("#"+proNum+" "+ans);
		}
		sc.close();
	}
}


/** 중간값 찾기
 *  카운팅 정렬 방식 아이디어를 적용, 빈도수를 구하여 들어온 숫자의 갯수/2 보다 클 때의 인덱스가 중간값이다
 */

import java.util.Scanner;
import java.io.*;

public class SWEA_2063_2 {
    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("input.txt")) {

            Scanner sc = new Scanner(fis);
            int n = sc.nextInt();
            int ans = 0;
            int[] arr = new int[n];
            int max = -1;

            for (int i = 0; i < n; i++) {
                int in = sc.nextInt();
                max = max > in ? max : in;
                arr[i] = in;
            }

            int[] tmpArr = new int[max + 1];

            for (int i = 0; i < arr.length; i++) {
                tmpArr[arr[i]]++;
            }

            int sum = 0;
            int idx = 0;
            while (true) {
                sum += tmpArr[idx++];
                if (sum > n / 2)
                    break;
            }

            System.out.println(idx - 1);

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
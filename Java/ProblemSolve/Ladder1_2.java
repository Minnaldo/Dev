/**
 *  * 문제의 특성을 이용한 문제
 *  * 거꾸로 찾아가야 계산 횟수가 줄어든다
 *  * 사다리 이므로, 존재하는 열은 무조건 꽉 차있다 --> 이는 가로로 넘어갈 때, 한번에 넘어갈수 있음
 *  * 이러한 생각을 바탕으로, 막대가 존재하는 열의 인덱스를 찾아 새로운 배열에 저장하고, 목적지가 존재하는 열을 찾는다.
 *  * 새로운 배열에서 목적지 열의 값을 갖고 있는 인덱스로부터 시작하여, 왼쪽으로 넘어갈땐 인덱스 감소, 오른쪽으로 넘어갈 땐 인덱스 증가를 하며 갱신
 */

import java.util.*;
import java.io.*;

public class Ladder1_2 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);

            for (int tc = 1; tc <= 10; tc++) {
                int ans = 0;
                int tt = sc.nextInt();

                int[][] map = new int[100][100];

                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < 100; j++) {
                        map[i][j] = sc.nextInt();
                    }
                }

                int idx = 0;
                int col_idx = 0;
                int[] arr = new int[100];
                for (int i = 0; i < 100; i++) {
                    if (map[99][i] == 1) {
                        arr[idx++] = i;
                    } else if (map[99][i] == 2) {
                        col_idx = idx;
                        arr[idx++] = i;
                    }
                }

                int cy = 99;
                while (cy-- > 0) {
                    if (col_idx > 0 && map[cy][arr[col_idx] - 1] == 1) {
                        // 왼쪽으로 가는게 있을 때
                        col_idx--;
                    } else if (col_idx < idx-1 && map[cy][arr[col_idx] + 1] == 1) {
                        // 오른쪽으로 가는게 있을 때
                        col_idx++;
                    }
                }
                ans = arr[col_idx];

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
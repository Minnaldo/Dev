import java.io.*;
import java.util.*;

/**
 *  REVIEW
 * * 모든 경우를 다 구해야 한다 * 1을 만날때마다 모든 크기의 색종이를 각각의 경우로 붙여보자 ==> 5진트리의 상태공간이 만들어짐 *
 * 붙을 수 있나, 없나 판단 조건 : 해당 색종이가 남아 있는가, 덮을 영역이 충분한가 * 위와 왼쪽이 비어있는 1은 최우선적으로 덮어야만
 * 하는 영역이다!!
 */

public class Colored_Paper {

    static int ans = 987654321;
    static int[][] map = new int[10][10];
    static int[] color_paper = { 0, 5, 5, 5, 5, 5 };

    // 가려야만 하는 지점(왼/위 가 비어있는 1)을 발견하면 색종이를 종류별로 붙이고 넘어가자
    static void recur(int cnt) {
        // 왼쪽과 위가 1인 위치를 찾는다. 없으면 완료이므로 현재 cnt를 정답에 저장(최소)
        // 있다면 가능한 모든 크기의 색종이로 붙이고 다음 재귀호출 해봄
        int startR = -1, startC = -1;
        out: for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 1) {
                    startR = i;
                    startC = j;
                    break out;
                }
            }
        }

        // 없으면 완료. 이므로 현재 cnt를 정답에 저장(최소 유지)
        if (startR == -1 && startC == -1) {
            ans = Math.min(ans, cnt);
            return;
        }

        // starR, startC로부터 붙일 수 있는 가장 큰 색종이는 어떤걸까?
        int max = 5;
        while (max > 0) {
            boolean isOk = true;
            out: for (int i = 0; i < max; i++) {
                for (int j = 0; j < max; j++) {
                    // startR, startC로부터 i,j만큼 떨어진 행렬의 위치가,
                    // 맵 밖으로 나가거나 0이 있으면 종료
                    if (startR + i >= 10 || startC + j >= 10 || map[startR + i][startC + j] == 0) {
                        isOk = false;
                        break out;
                    }
                }
            }
            if (isOk)
                break;
            max--;
        }

        // 있다면 가능한 모든 크기의 색종이로 붙이고 다음 재귀호출 해봄
        for (int i = max; i > 0; i--) {
            if (color_paper[i] > 0) {
                // startR, startC 부터 max크기 만큼의 정사각형을 0으로 바꾸고, 색종이 줄여주기
                for (int a = startR; a < startR + i; a++) {
                    for (int b = startC; b < startC + i; b++) {
                        map[a][b] = 0;
                    }
                }
                // i x i 크기 색종이 갯수 감소
                color_paper[i]--;
                // 재귀 호출하고
                recur(cnt + 1);
                // startR, startC부터 max 크기 만큼의 정사각형을 1로 바꾸기, 색종이 늘려주기
                for (int a = startR; a < startR + i; a++) {
                    for (int b = startC; b < startC + i; b++) {
                        map[a][b] = 1;
                    }
                }
                // i x i 크기 색종이 갯수 증가
                color_paper[i]++;
            }
        }

    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            for (int i = 0; i < 10; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 10; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            recur(0);
            ans = ans == 987654321 ? -1 : ans;

            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
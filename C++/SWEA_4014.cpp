#include <algorithm>
#include <fstream>
#include <iostream>

/** 활주로 건설 - 오르막 / 내리막을 건설하여 횡단할 수 있는 방법의 수를 구하라
 *  * simulation problem
 */

using namespace std;

int arr[20][20];
int N, X, ans;

void solution()
{
    int preH = 0;
    for (int i = 0; i < N; i++)
    {
        int len = 0;
        int preH = arr[i][0];

        for (int j = 0; j < N; j++)
        {
            if (preH == arr[i][j])
                len++;
            else if (preH == arr[i][j] - 1)
            {
                // 오르막
                if (len < X)
                    break; // 평지 수가 X보다 작으면 오르막 / 내리막 만들기 불가 함
                len = 1;   // 올라간 땅 부터 시작하므로 1로 초기화
            }
            else if (preH == arr[i][j] + 1)
            {
                // 내리막
                if (len < 0)
                    break;    // len < 0 이면 내리막을 만들던 도중 이므로, 더이상 만들수 없음 그러므로 종료
                len = -X + 1; // 내리막을 만들 때 X길이만큼의 땅이 필요 하므로 -X+1
            }
            else
                break; // 높이차 2 이상 이므로 종료

            preH = arr[i][j]; // 다음 순서에 여기서부터 탐색
            if (j == N - 1)
            {
                // 완전히 탐색하였을 때
                if (len < 0)
                    break; // len < 0 내리막을 만들었는데, 길이가 안될 경우
                else
                    ans++;
            }
        }

        len = 0;
        preH = arr[0][i];
        for (int j = 0; j < N; j++)
        {
            if (preH == arr[j][i])
                len++;
            else if (preH == arr[j][i] - 1)
            {
                // 오르막
                if (len < X)
                    break;
                len = 1;
            }
            else if (preH == arr[j][i] + 1)
            {
                // 내리막
                if (len < 0)
                    break;
                len = -X + 1;
            }
            else
                break;

            preH = arr[j][i];
            if (j == N - 1)
            {
                if (len < 0)
                    break;
                else
                    ans++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int T;
    // scanf("%d", &T);
    fs >> T;

    for (int t = 1; t <= T; t++)
    {
        // scanf("%d %d", &N, &X);
        fs >> N >> X;
        ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                // scanf("%d", &arr[i][j]);
                fs >> arr[i][j];

        solution();
        printf("#%d %d\n", t, ans);
    }
    return 0;
}
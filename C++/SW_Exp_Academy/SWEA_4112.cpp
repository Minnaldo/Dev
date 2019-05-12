#include <iostream>

/**
 *  * 현재 있는 방에 접해있는 방을 찾는다
 *  * dfs를 이용한다? --> 그렇다면 가지치기의 조건은?
 *  * 보물이 있는 방번호와 내가 있는 방 번호의 차를 이용하여 탐색범위를 줄인다.
 */

using namespace std;

int t, mj, fin, finidx, findst, ans;
int arr[142]; // 인덱스(줄 번호) 번째 방까지 방의 갯수, 현재 줄에 있는 방의 수 = arr[idx] - arr[idx-1]

int min(int &a, int &b) { return a < b ? a : b; }

// 현재 방이 몇번째 줄에 있는지 찾아보자
// 141줄 이내, 뺀것에+1, 더한것에+1
int init(int roomNum)
{
    int sum = 0;
    arr[0] = 0;
    for (int i = 1; i <= 141; i++)
    {
        sum += i;
        arr[i] = sum;

        // TODO need to get line number
        if (arr[i - 1] + 1 <= roomNum && roomNum <= arr[i])
        {
            return i;
        }
    }
}

void solution(int curRoomNum, int cnt, int idx)
{
    if (cnt > ans)
    {
        return;
    }

    if (curRoomNum == fin)
    {
        ans = min(ans, cnt);
        return;
    }

    if (curRoomNum - fin < 0 && fin > arr[idx]) // 현재 방보다 보물이 밑줄에 있는 경우
    {
        // int ldst = 0, rdst = 0;

        // ldst = curRoomNum - arr[idx - 1] + 1;
        // rdst = arr[idx] - curRoomNum;
        // int finrdst = arr[finidx] - fin, finldst = fin - arr[finidx - 1] + 1;

        if (cnt + (finidx - idx) > ans)
            return;

        solution(curRoomNum + idx + 1, cnt + 1, idx + 1);
        solution(curRoomNum + idx, cnt + 1, idx + 1);
    }
    else if (curRoomNum - fin > 0 && fin < arr[idx - 1] + 1) // 현재 방보다 보물이 윗줄에 있는 경우
    {
        // 현재 방이 모서리에 있는 경우
        if (arr[idx - 1] + 1 == mj || arr[idx] == mj)
        {
            if (arr[idx - 1] + 1 == mj)
            {
                // 피라미드 왼쪽 모서리에 있는 경우
                solution(curRoomNum - idx + 1, cnt + 1, idx - 1);
            }
            else
            {
                // 피라미드 오른쪽 모서리에 있는 경우
                solution(curRoomNum - idx, cnt + 1, idx - 1);
            }
        }
        else if (arr[idx - 1] + 1 <= mj && arr[idx] >= mj)
        {
            // 현재 방이 모서리에 있지 않은경우
            solution(curRoomNum - idx + 1, cnt + 1, idx - 1);
            solution(curRoomNum - idx, cnt + 1, idx - 1);
        }
    }
    else if (arr[idx - 1] + 1 <= curRoomNum && curRoomNum <= arr[idx]) // 같은 줄에 있을 경우 --> 좌, 우 로만 이동하면 된다
    {
        if (curRoomNum - fin > 0)
        {
            solution(curRoomNum + 1, cnt + 1, idx);
        }
        else
        {
            solution(curRoomNum - 1, cnt + 1, idx);
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        ans = 100001;

        scanf("%d %d", &mj, &fin);
        int idx = init(mj);
        finidx = init(fin);

        solution(mj, 0, idx);
        printf("#%d %d\n", tc, ans);
    }

    return 0;
}
#include <deque>
#include <iostream>
#include <vector>

/**
 *  ! 배열 및 벡터 사용시 인덱스 확인 잘하기!
 */

using namespace std;

int k;
int operation[20][2];
vector<deque<int>> magnet(4, deque<int>(8));
vector<pair<int, int>> tmpArr(4);
bool visit[4];

void rotation(int flag, int idx)
{
    if (flag > 0)
    {
        int tmp = magnet[idx].back();
        magnet[idx].pop_back();
        magnet[idx].push_front(tmp);
    }
    else
    {
        int tmp = magnet[idx].front();
        magnet[idx].pop_front();
        magnet[idx].push_back(tmp);
    }
}
// ! 종료조건
void change(int flag, int idx) // 0, 1, 2, 3
{
    // 인덱스가 벗어나면 종료
    if (idx < 0 || idx > 3)
        return;

    if (!visit[idx])
    {
        visit[idx] = true; // 이번 단계에 회전을 했는지 안했는지 판단 함수
        rotation(flag, idx);

        // 각 자석에 대해 회전 여부 설정
        if (idx == 0)
        {
            if (tmpArr[idx].second != tmpArr[idx + 1].first)
                change(-flag, idx + 1);
        }
        else if (idx == 3)
        {
            if (tmpArr[idx].first != tmpArr[idx - 1].second)
                change(-flag, idx - 1);
        }
        else
        {
            if (tmpArr[idx].first != tmpArr[idx - 1].second)
                change(-flag, idx - 1);

            if (tmpArr[idx].second != tmpArr[idx + 1].first)
                change(-flag, idx + 1);
        }
    }
}

int solution()
{
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int mgIdx = operation[i][0] - 1;
        int clwise = operation[i][1];

        for (int i = 0; i < 4; i++)
        {
            tmpArr[i].second = magnet[i][2];
            tmpArr[i].first = magnet[i][6];
        }

        change(clwise, mgIdx);

        fill_n(visit, 4, false);
    }

    ans += magnet[0].front() == 1 ? 1 : 0;
    ans += magnet[1].front() == 1 ? 2 : 0;
    ans += magnet[2].front() == 1 ? 4 : 0;
    ans += magnet[3].front() == 1 ? 8 : 0;
    return ans;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++)
    {
        int ans = 0;
        scanf("%d", &k);

        // 자석 입력
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                scanf("%d", &magnet[i][j]);
            }
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                scanf("%d", &operation[i][j]);
            }
        }

        ans = solution();
        printf("#%d %d\n", test_case, ans);
    }

    return 0;
}
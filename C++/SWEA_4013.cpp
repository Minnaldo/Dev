#include <deque>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int k;
int operation[2][20];
vector<deque<int>> magnet(4);
vector<pair<int, int>> tmpArr(4);

void rotation(int flag, int idx)
{
    int tmp;
    if (flag == 1)
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

void func()
{
    for( int i = 0; i<4; i++ )
    {
        tmpArr[i].first =  magnet[i][2];
        tmpArr[i].second = magnet[i][6];
    }
}

void change(int flag, int idx) // 0, 1, 2, 3
{
    if (idx < 0 || idx > 3)
        return;

    int pre = magnet[idx][2], post = magnet[idx][6];
    rotation(flag, idx);

    flag = flag == 1 ? 0 : 1;
    if (idx + 1 < 4)
        if (tmpArr[idx].first != tmpArr[idx-1].second)
            change(flag, idx - 1);

    if (idx - 1 > 0)
        if (tmpArr[idx].second != tmpArr[idx+1].first)
            change(flag, idx + 1);
}

int solution()
{
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int mgIdx = operation[i][0] - 1;
        // cout << operation[1][i] << endl;
        int clwise = operation[i][1] == 1 ? 1 : 0;

        func();
        change(clwise, mgIdx);

        // for (int j = 0; j < 4; j++)
        // {
        //     for (int a = 0; a < 8; a++)
        //     {
        //         cout << magnet[j][a] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    ans += magnet[0].front() == 1 ? 1 : 0;
    ans += magnet[1].front() == 1 ? 2 : 0;
    ans += magnet[2].front() == 1 ? 4 : 0;
    ans += magnet[3].front() == 1 ? 8 : 0;
    return ans;
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    // ios::sync_with_stdio(false);
    int T;
    // scanf("%d", &T);
    fs >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        int ans = 0;
        // scanf("%d", &k);
        fs >> k;

        // 자석 입력
        for (int i = 0; i < 4; i++)
        {
            int tmp;
            for (int j = 0; j < 8; j++)
            {
                // scanf("%d", &tmp);
                fs >> tmp;
                magnet[i].push_back(tmp);
            }
        }

        for (int i = 0; i < k; i++)
        {
            int tmp;
            for (int j = 0; j < 2; j++)
            {
                // scanf("%d", &tmp);
                fs >> tmp;
                operation[i][j] = tmp;
            }
        }

        ans = solution();
        printf("#%d %d\n", test_case, ans);
    }

    return 0;
}
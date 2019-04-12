#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

/**
 *  ! 시간초과
 */

using namespace std;

int ans, t, w, d, k, result;
vector<vector<int>> film(13, vector<int>(20));

// 보호필름 확인 후 통과 가능하면 true, 아니면 false 반환
bool isPass(vector<vector<int>> arr)
{
    int passfail = 0;
    for (int j = 0; j < w; j++)
    {
        int len = 1;

        for (int i = 1; i < d; i++)
        {
            if (arr[i][j] == arr[i - 1][j])
                len++; // 연속된 셀 타입의 길이 저장
            else
                len = 1;

            if (len >= k)
            {
                passfail++;
                break;
            }
            if (i == d - k + 1 && arr[i][j] != arr[i - 1][j])
                return false;
        }

        if (j + 1 != passfail)
            return false;
    }

    return true;
}

void dfs(vector<vector<int>> arr, int depth, int cnt)
{
    if (cnt >= result)
        return;

    if (isPass(arr))
    {
        result = result < cnt ? result : cnt;
        return;
    }

    if (depth < d && cnt < result)
    {
        dfs(arr, depth + 1, cnt);

        fill_n(arr[depth].begin(), w, 1);
        dfs(arr, depth + 1, cnt + 1);

        fill_n(arr[depth].begin(), w, 0);
        dfs(arr, depth + 1, cnt + 1);
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    fs >> t;
    // scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        ans = 0;
        result = 9876;
        // scanf("%d %d %d", &d, &w, &k);
        fs >> d >> w >> k;

        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < w; j++)
            {
                // scanf("%d", &film[i][j]);
                fs >> film[i][j];
            }
        }

        if (k == 1 || isPass(film))
        {
            ans = 0;
        }
        else
        {
            dfs(film, 1, 0);
            fill_n(film[0].begin(), w, 1);
            dfs(film, 1, 0);
            fill_n(film[0].begin(), w, 1);
            dfs(film, 1, 0);
            ans = result;
        }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
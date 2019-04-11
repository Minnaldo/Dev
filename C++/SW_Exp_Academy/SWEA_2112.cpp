#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int ans, t, w, d, k, cnt;
vector<vector<int>> film(13, vector<int>(20));

int min(int &a, int &b) { return a > b ? a : b; }

// 보호필름 확인 후 통과 가능하면 true, 아니면 false 반환
bool func(vector<vector<int>> arr)
{
    bool ret;
    for (int i = 0; i < w; i++)
    {
        int tmp = arr[0][i];
        int len = 0;
        for (int j = 1; j < d; j++)
        {
            if (tmp == arr[j][i])
                len++;
            else
                len = 1;
        }

        if (len < k)
            return false;
    }
    return true;
}

// @param type : film type (1 or 0)
void dfs(vector<vector<int>> arr, int height)
{
    if (func(arr) && cnt > 0)
    {
        cnt + 1;
        return;
    }
    // else
    //     cnt;

    // 바꾸기 전 상태 임시 저장
    vector<int> tmparr(w);
    tmparr.assign(arr[height].begin(), arr[height].end());

    if (height < d)
    {
        fill_n(arr[height], w, 1); // 한 줄을 type B 로 변경
        dfs(arr, height + 1);
        fill_n(arr[height], w, 0); // 한 줄을 type A 로 변경
        dfs(arr, height + 1);
        arr[height].assign(tmparr.begin(), tmparr.end()); // 바꾼 배열 복구
        dfs(arr, height + 1);
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    fs >> t;
    // scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        ans = cnt = 0;

        // scanf("%d %d %d", &d, &w, &k);
        fs >> d >> w >> k;

        for (int i = 0; i < d; i++)
            for (int j = 0; j < w; j++)
                // scanf("%d", &film[i][j]);
                fs >> film[i][j];

        if (func(film)) // 아무 것도 안막고 바꿀 수 있으면 0 반환
        {
            ans = 0;
        }
        else
        {
            ans = 1;
            ans = min(ans, cnt);
        }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
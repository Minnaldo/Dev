#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int ans, t, w, d, k, result;
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
// 약품 처리 시 마다 판단을 하고 다음 단계로 넘어간다면???
void dfs(vector<vector<int>> arr, int height, int cnt)
{
    if (func(arr) && cnt > 0)
    {
        result = result > cnt ? cnt : result;
        return;
    }
    // else
    //     cnt;

    // 바꾸기 전 상태 임시 저장
    vector<int> tmparr(w);
    tmparr.assign(arr[height].begin(), arr[height].end());

    if (height < d)
    {
        fill_n(arr[height].begin(), w, 1); // 한 줄을 type B 로 변경
        dfs(arr, height + 1, cnt + 1);
        fill_n(arr[height].begin(), w, 0); // 한 줄을 type A 로 변경
        dfs(arr, height + 1, cnt + 1);
        arr[height].assign(tmparr.begin(), tmparr.end()); // 바꾼 배열 복구
        dfs(arr, height + 1, cnt + 1);
    }
}

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    fs >> t;
    // scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        ans = result = 0;

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
            dfs(film, 0, 1);
            ans = result; // ! 이부분이 잘못된거같은데
        }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
#include <sstream>
#include <iostream>

using namespace std;

/**
 *  ! 최대 행복도를 구하라
 *  * Dynamic Programming Problem
 *  * recursuion Fomular
 */

// 개설 교과목 수 최대 200,000개
int dp[200001][2];

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int m, int **arr, int lo, int hi)
{
    int curHak, curHang;
    //  TODO  알고리즘을 조금 더 생각해봐야 할듯
    if (lo <= curHak + arr[i][0] && hi >= curHak + arr[i][0])
    {
        curHang += arr[i][1];
        curHak += arr[i][0];
    }

    int answer = dp[1][1];

    for (int i = 2; i <= m; i++)
    {
        answer = max(answer, dp[i][1]);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    string input = "2 2 4 0 2 1 1 1 3 1 -1";
    stringstream ss;
    ss.str(input);

    int lo, hi;
    // cin>>lo>>hi;
    ss >> lo >> hi;

    int m; // 개설 과목의 수
    // cin>>m;
    ss >> m;

    int **arr = new int *[m + 1];

    for (int i = 1; i <= m; i++)
    {
        arr[i] = new int[2];
        int hak, hang;
        // cin>>hak>>hang;
        ss >> hak >> hang;
        // ss >> hang;
        arr[i][0] = hak;
        arr[i][1] = hang;
    }
    cout << solution(m, arr, lo, hi) << endl;
    //배열 출력위한 임시
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << arr[i][0] << "  " << arr[i][1] << endl;
    // }

    return 0;
}
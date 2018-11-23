#include <iostream>
#include <sstream>
#include <chrono>
// #include <fstream>

#define red 0
#define green 1
#define blue 2

using namespace std;

int N, dp[1000]; // 집의 수 <= 1000
int preColor = -1;

int min(int a, int aColor, int b, int bColor)
{
    if (a < b)
    {
        preColor = aColor;
        return a;
    }
    else
    {
        preColor = bColor;
        return b;
    }
}

//동적 할당 2차원 배열 전달 받기
int solution(int **cost)
{
    for (int i = 1; i < N; i++)
    {
        if (preColor == red)
        {
            dp[i] = min(dp[i - 1] + cost[i][green], green, dp[i - 1] + cost[i][blue], blue);
        }
        else if (preColor == green)
        {
            dp[i] = min(dp[i - 1] + cost[i][red], red, dp[i - 1] + cost[i][blue], blue);
        }
        else
        {
            dp[i] = min(dp[i - 1] + cost[i][red], red, dp[i - 1] + cost[i][green], green);
        }
    }

    return dp[N - 1];
}

int main(int argc, char const *argv[])
{
    stringstream ss;
    string in_file = "3 26 40 83 49 60 57 13 89 99";
    ss.str(in_file);

    auto start = chrono::steady_clock::now();

    int n, tmp;
    ss >> n;
    N = n;
    int **cost = new int *[n];

    for (int i = 0; i < n; i++)
    {
        cost[i] = new int[3]; //  n * 3 배열 동적 선언
        for (int j = 0; j < 3; j++)
        {
            ss >> tmp;
            cost[i][j] = tmp;
        }
    }

    dp[0] = min(cost[0][0], red, cost[0][1], green);
    dp[0] = min(cost[0][preColor], preColor, cost[0][2], blue);
    cout << solution(cost) << endl;


    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);

    cout << "Duration : " <<duration.count()/1000000.0<<  " ms" << endl;
    // 동적 할당 2차원 배열 메모리 해제
    for (int i = 0; i < n; i++)
    {
        delete[] cost[i];
    }
    delete[] cost;

    return 0;
}
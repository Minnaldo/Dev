#include <iostream>
#include <vector>
#include <fstream>

/** 하얀 칸 백준_1100 (https://www.acmicpc.net/problem/1100)
 *  * 체스판 위에서 하얀칸을 찾는 문제
 */

using namespace std;

int solution(vector<vector<int>> &arr)
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 != 0 && j % 2 != 0) // 짝수칸 --> 1 3 5 7
            {
                if (arr[i][j] == 1)
                    cnt++;
            }
            else if (i % 2 == 0 && j % 2 == 0)// 홀수칸 --> 2 4 6 8
            {
                if (arr[i][j] == 1)
                    cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr(8, vector<int>(8, 0));

    ifstream fs("input.txt");
    char c;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            fs >> c;
            if (c == 'F')
            {
                arr[i][j] = 1;
            }
            else if (c == '.')
            {
                arr[i][j] = 0;
            }
        }
    }

    cout << solution(arr) << endl;
    return 0;
}
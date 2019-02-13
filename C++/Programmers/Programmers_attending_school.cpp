#include <utility>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

/** 프로그래머스 등굣길 (https://programmers.co.kr/learn/courses/30/lessons/42898)
 *  * DP 또는 BFS로 풀이 가능
 */

int dp[100][100];
// bool visit[100][100];
// int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// // 조합을 구하는 함수, 조합을 dp로(?)
// int combination(int n, int r)
// {
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= r; j++)
//         {
//             if (i == j || j == 0)
//             {
//                 arr[i][j] = 1;
//             }
//             else
//             {
//                 arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//             }
//         }
//     }
//     return arr[n][r];
// }

// int BFS(int m, int n, vector<vector<int>> pp)
// {
//     //웅덩이 전처리
//     for(int i = 0; i< pp.size(); i++)
//     {
//         arr[pp[i][0]][pp[i][1]] = 0;
//     }

//     queue<pair<int, int>> q;
//     q.push(make_pair(0, 0)); //0,0 부터 시작
//     visit[0][0] = true;

//     while (!q.empty())
//     {
//         int cur_ypos = q.front().first;
//         int cur_xpos = q.front().second;

//         for (int i = 0; i < 4; i++)
//         {
//             int nxt_ypos = cur_ypos + dir[i][0];
//             int nxt_xpos = cur_xpos + dir[i][1];

//             if (nxt_ypos >= 0 && nxt_ypos <= n && nxt_xpos >= 0 && nxt_xpos <= m)
//             {
//                 if (!visit[nxt_ypos][nxt_xpos] && arr[nxt_ypos][nxt_xpos])
//                 {
//                     q.push(make_pair(nxt_ypos, nxt_xpos));
//                     visit[nxt_ypos][nxt_xpos] = true;

//                 }
//             }
//         }

//         q.pop();
//     }

//     return arr[n-1][m-1];
// }

int dynamicProgramming(int m, int n, vector<vector<int>> pp)
{
    dp[0][0] = 1;
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {

        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles)
{

    int tmp, pudSize = puddles.size();
    //갈 수있는 모든 수 (웅덩이 무시)
    int whole = combination(m + n, n);
    vector<int> tmpVec;

    if (pudSize <= 1)
    {
        int tmp1 = m - puddles[0][0] + 1;
        int tmp2 = n - puddles[0][1] + 1;
        tmpVec.push_back(combination(puddles[0][0] + puddles[0][1], puddles[0][1]));
        tmpVec.push_back(combination(tmp1 + tmp2, tmp2));
    }
    else
    {
        tmpVec.push_back(combination(puddles[0][0] + puddles[0][1], puddles[0][1]));
        for (int i = 1; i < pudSize; i++)
        {
            int tmp1 = puddles[i][0] - (puddles[i - 1][0] - 1), tmp2 = puddles[i][1] - (puddles[i - 1][1] - 1);
            tmpVec.push_back(combination(tmp1 + tmp2, tmp2));
        }
    }

    int tVecSize = tmpVec.size();
    for (int i = 0; i < tVecSize; i++)
    {
        whole -= tmpVec[i];
    }
    return whole % 1000000007;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> forbidden = {{2, 2}};
    cout << solution(4, 3, forbidden) << endl;
    return 0;
}
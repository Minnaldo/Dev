#include <string>
#include <vector>
#include <iostream>

using namespace std;

/***
 * 네트워크 문제, 네트워크가 몇개인가?
 * 깊이 우선 탐색 - DFS를 활용하여 문제푼다
 * 순환을 이용하면 편하며, visit은 방문여부를 확인하는 배열
 * Computers행렬은 N x N 행렬이지만 visit의 크기가 N인 이유는  Computers가 대칭행렬이기 때문에
 * 한쪽 면만 검색을 하여도 되기 때문이다.
*/

//cnt : 네트워크 카운트 변수
int com_size, cnt;
//visit 방문 여부 판단 배열
bool visit[200];

void dfs(int current, vector<vector<int>> computers)
{
    visit[current] = true;
    for (int i = 0; i < com_size; i++)
    {
        if (computers[current][i] == 1 && !visit[i])
        {
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    com_size = n;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i, computers);
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int coms = 3;
    cout << solution(coms, arr) << endl;
    return 0;
}

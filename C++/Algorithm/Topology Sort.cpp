#include <iostream>
#include <queue>
#include <vector>

/** Topology Sort ( 위상 정렬 )
 *  * 가정 1) 백준 ACM Craft의 문제와 같이 순서도가 들어온다는 가정하에 시행
 */

using namespace std;

vector<vector<int>> sequence(10000, vector<int>(2));
vector<int> degree(10000);

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    // n개의 build up 경우의 수 입력 받음
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> sequence[i][j];
            if (j == 1)
                degree[sequence[i][j]]++;
        }
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>

/** 조세퍼스 문제 0 백준_1158 ( https://www.acmicpc.net/problem/1158 )
 *  TODO spend much time. so,
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, tmp;
    scanf("%d %d", &n, &m);

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }

    while (!q.empty())
    {
        int size = q.size();
        if (size >= m)
        {
            for (int i = 0; i < m - 1; i++)
            {
                q.push(q.front());
                q.pop();
            }
            tmp = q.front();
            q.pop();
            ans.push_back(tmp);
        }
        else if (q.size() == 1)
        {
            ans.push_back(q.front());
            q.pop();
        }
        else
        {
            for (int i = 0; i < (m - size)-1; i++)
            {
                q.push(q.front());
                q.pop();
            }
            tmp = q.front();
            q.pop();
            ans.push_back(tmp);
        }
    }

    int size = ans.size() - 1;
    printf("<");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", ans[i]);
    }
    printf("%d>\n", ans[size]);

    return 0;
}
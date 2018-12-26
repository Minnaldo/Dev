#include <fstream>
#include <iostream>

/** 트리 백준_1068 (https://www.acmicpc.net/problem/1068)
 *  * 트리를 배열로 구현해낼 수 있다.
 */

using namespace std;

int tree[51];

int solution(int *arr, int idx, int n)
{
    for (int i = idx; i <= n; i++)
    {
        if (i * 2 <= n || (i * 2) + 1 <= n)
        {
            arr[i] = -2;
            arr[i + 1] = -2;
        }
    }

    int ans = 0;

    //  트리의 말단 노드 탐색을 어떻게 할것인가?
    //  말단 노드의 조건 --> 자식 노드가 없다.
    //  자식 노드가 없는 것의 판별은??  나의 인덱스 * 2 가 없고 나의 인덱스 *2 +1 도 없다 (-2 or NULL)
    // TODO


    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return ans;
}

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt");
    int del, lim;
    fs >> lim;

    int *arr = new int[lim + 1];

    for (int i = 1; i <= lim; i++)
    {
        fs >> arr[i];
    }
    fs >> del;
    cout << solution(arr, del + 1, lim) << endl;

    // for (int i = lim; i > 0; i--)
    // {
    //     if (arr[i] != -2)
    //     {
    //         cnt++;
    //     }
    // }

    return 0;
}
#include <fstream>
#include <iostream>

/** 트리 백준_1068 (https://www.acmicpc.net/problem/1068)
 *  * 트리를 배열로 구현해낼 수 있다.
 */

using namespace std;

int solution(int* tree, int idx, int n)
{
    int tmp = idx, ans = 0;
    while (tmp <= n)
    {
        tmp *= 2;
        tree[tmp] = -2;
        tree[tmp + 1] = -2;
    }

    for (int i = n; i > 0; i--)
    {
        if (tree[i / 2] > -1 && (tree[i * 2] == -2 && tree[(i * 2) + 1] == -2))
            ans++;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt");
    int del, lim;
    fs >> lim;

    int *tree = new int[101];

    for (int i = 1; i <= lim; i++)
    {
        fs >> tree[i];
    }
    fs >> del;

    // 전처리
    for (int i = lim + 1; i <= 101; i++)
    {
        tree[i] = -2;
    }

    cout << solution(tree, del + 1, lim) << endl;

    return 0;
}
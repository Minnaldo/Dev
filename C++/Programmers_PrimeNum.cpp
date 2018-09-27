#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

/*
    에라토스테네스의 체를 이용한 2-N사이 소수들의 합
*/
int main(int argc, char const *argv[])
{
    int N = 10000;
    long long answer = 0;
    vector<int> pNum;

    auto start = chrono::high_resolution_clock::now();

    pNum.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        pNum[i] = i + 1;
    }
    pNum.at(0) = 0;
    for (int i = 2; i <= N; i++)
    {
        if (pNum[i - 1] != 0)
        {
            for (int j = i * 2; j <= N; j += i)
            {
                pNum[j - 1] = 0;
            }
        }
    }

    for (int i = 0; i < pNum.size(); i++)
    {
        answer += pNum[i];
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Time : " <<(float) (end - start).count()/CLOCKS_PER_SEC << endl;
    cout << "Answer : " << answer << endl;

    return 0;
}
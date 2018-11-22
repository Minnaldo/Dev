#include <vector>
#include <cmath>
#include <chrono>
#include <iostream>

using namespace std;

vector<long long> arr;
vector<long long> multiple;

long long func(long long n)
{
    arr.push_back(1);
    arr.push_back(3);

    int tmpIdx = -1;
    float cnt = 2;

    while (true)
    {
        tmpIdx++;
        int mul = pow(2, tmpIdx) - 1;
        if (n <= mul)
        {
            break;
        }
    }
    //3^tmpidx 까지 구하면 됨

    for (int i = 2; i < tmpIdx; i++)
    {
        int tmp = pow(2,i)-1;
        for(int j = 0; j<tmp; j++)
        {
            arr.push_back(arr.back()+arr[j]);
        }
        arr.push_back(pow(3,i));
    }

    for(int i = 0; i<arr.size(); i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return arr[n-1];
}

long long solution(long long n)
{
    long long answer = func(n);
    return answer;
}

int main(int argc, char const *argv[])
{
    long long n = 11;
    auto start = chrono::system_clock::now();
    cout << "Test 1 : " << solution(n) << "\t";
    auto end = chrono::system_clock::now();

    cout << "Duration : " << (float)(end - start).count() / CLOCKS_PER_SEC << " sec" << endl;

    return 0;
}
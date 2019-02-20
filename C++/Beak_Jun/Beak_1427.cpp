#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, tmp,idx = 0;
    cin >> N;
    vector<int> vec;
    while (N != 0)
    {
        tmp = N % 10;
        N /= 10;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());
    auto itr = vec.end();
    for(--itr; itr>=vec.begin(); itr--)
    {
        cout<<*itr;
    }
    cout<<endl;

    return 0;
}
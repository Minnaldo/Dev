#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int arr[500000], freq[500000];

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int n;
    // scanf("%d", &n);
    fs >> n;
    int *freq = new int[n];
    map<int, int> mp;

    int sum = 0, min = 4001, max = -4001, fre = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", &tmp);
        fs >> tmp;
        arr[i] = tmp;
        mp[tmp]++;
        sum += tmp;
        min = min < tmp ? min : tmp;
        max = max > tmp ? max : tmp;
    }

    sort(arr, arr + n);
    int mid = arr[n / 2 + 1];

    auto itr = mp.begin();
    int mode;
    for (itr; itr != mp.end(); itr++)
    {
        if (fre < itr->second)
        {
            fre = itr->second;
            mode = itr->first;
        }
    }

    int avg = sum / n;
    if (sum % n >= 5)
        avg++;

    printf("%d\n%d\n%d\n%d\n", avg, mid, fre, (max - min));

    return 0;
}
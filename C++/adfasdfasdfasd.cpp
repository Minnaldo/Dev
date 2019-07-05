#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int ans = n;

    unordered_map<int, int> hmap;

    for (int aa : lost)
        hmap[aa]--;

    for (int &aa : reserve)
    {
        if (hmap.find(aa) != hmap.end() && hmap[aa] < 0)
        {
            hmap[aa]++;
        }
        else if (hmap.find(aa - 1) != hmap.end() && hmap[aa - 1] < 0)
        {
            hmap[aa - 1]++;
        }
        else if (hmap.find(aa + 1) != hmap.end() && hmap[aa + 1] < 0)
        {
            hmap[aa + 1]++;
        }
    }

    for (auto me : hmap)
        if (me.second < 0)
            ans--;

    return ans;
}

int main(int argc, char const *argv[])
{

    cout << solution(3, {3}, {1}) << endl;
    return 0;
}
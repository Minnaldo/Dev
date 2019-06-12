#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> permut;

void save(string str, int size)
{
    string tmp;
    for (int i = 0; i < size; i++)
    {
        tmp += str[i];
    }
    try
    {
        permut.push_back(stoi(tmp));
    }
    catch (const std::exception &e)
    {
    }
}

void permu(string arr, int n, int r, int depth)
{
    if (depth == r)
    {
        // end
        save(arr, r);
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(arr[depth], arr[i]);
        permu(arr, n, r, depth + 1);
        swap(arr[depth], arr[i]);
    }
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;

    int limit = sqrt(num);
    for (int i = 2; i <= limit; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    int size = numbers.size();
    for (int i = 0; i <= size; i++)
        permu(numbers, size, i, 0);

    // 중복제거
    sort(permut.begin(), permut.end());
    permut.erase(unique(permut.begin(), permut.end()), permut.end());

    for (int aa : permut)
    {
        if (isPrime(aa))
            answer++;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string number = "17"; // ans : 3
    cout << solution(number) << endl;
    return 0;
}
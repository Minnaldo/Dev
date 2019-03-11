#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, answer, n;
    cin >> N;

    answer = N / 5;

    if (N % 5 != 0)
    {
        int tmp = 0;
        while (N % 3 != 0)
        {
            answer--;
            n -= 5 * answer;
            tmp++;
        }

        if (answer == 0 && n > 0 && n < 3)
            answer = -1;
        else
            answer += tmp;
    }

    cout << answer << endl;

    return 0;
}
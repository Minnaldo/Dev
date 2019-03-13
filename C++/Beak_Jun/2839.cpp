#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, answer = 0, five, three;
    cin >> N;

    if (N % 5 != 0)
    {
        five = N / 5;
        int tmp = N % 5;
        if (tmp % 3 == 0)
        {
            three = tmp / 3;
        }
        else
        {
        }
    }

    if ((five * 5) + (three * 3) != N)
    {
        answer = -1;
    }
    else
    {
        answer = five + three
    }

    cout << answer << endl;

    while (true)
    {
        if (five * 5 + three * 3 > N)
        {
            answer = -1;
            break;
        }

        if (N == (five * 5) + (three * 3))
        {
            answer = five + three;
            break;
        }

        five--;
        three++;
    }

    return 0;
}
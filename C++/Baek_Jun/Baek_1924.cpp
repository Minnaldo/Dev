#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int M, D;
    cin >> M >> D;

    int tmp = D;

    for (int i = 1; i < M; i++)
    {
        if (M > 1)
        {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                tmp += 31;
            }
            else if (i == 2)
            {
                tmp += 28;
            }
            else
            {
                tmp += 30;
            }
        }
    }

    switch (tmp % 7)
    {
    case 0:
        cout << "SUN" << endl;
        break;
    case 1:
        cout << "MON" << endl;
        break;
    case 2:
        cout << "TUE" << endl;
        break;
    case 3:
        cout << "WED" << endl;
        break;
    case 4:
        cout << "THU" << endl;
        break;
    case 5:
        cout << "FRI" << endl;
        break;
    case 6:
        cout << "SAT" << endl;
        break;
    }
    return 0;
}
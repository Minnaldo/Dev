#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// vector<int> solution(int money)
// {
//     vector<int> answer;

//     int aa = 50000;

//     for (int i = 0; i < 9; i++)
//     {
//         int tmp = 0;
//         if (i % 2 == 0)
//         {
//             tmp = money / aa;
//             aa /= 5;
//         }
//         else
//         {
//             tmp = money / aa;
//             aa /= 2;
//         }

//         answer.push_back(tmp);
//     }

//     return answer;
// }

int main(int argc, char const *argv[])
{
    int money = 0;
    cin >> money;

    vector<int> answer;

    int aa = 50000;

    for (int i = 0; i < 9; i++)
    {
        int tmp = 0;
        if (i < 8)
        {
            if (i % 2 == 0)
            {
                tmp = money / aa;
                money = money % aa;
                aa /= 5;
            }
            else
            {
                tmp = money / aa;
                money = money % aa;
                aa /= 2;
            }
        }
        else
        {
            tmp = money / 1;
        }

        answer.push_back(tmp);
    }

    for (int i = 0; i < 9; i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}
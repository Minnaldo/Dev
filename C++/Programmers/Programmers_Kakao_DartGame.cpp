#include <vector>
#include <string>
#include <iostream>
#include <cmath>

/** 다트 게임_프로그래머스 (https://programmers.co.kr/learn/courses/30/lessons/17682)
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int answer = 0;
    string dartResult = "1S2D*3T";
    int strlen = dartResult.length(); //7
    vector<int> numdart(strlen);
    vector<int> bonusidx(3);
    vector<int> calcBonus(3);

    for (int i = 0; i < strlen; i++)
    {
        numdart[i] += (int)dartResult[i];
        // cout << numdart[i] << " ";
    }

    //bonusidx[0~2] = 1,3,6
    int tmpidx = 0;
    for (int idx = 0; idx < numdart.size(); idx++)
    {
        if (numdart[idx] >= 65 && numdart[idx] <= 90) //A~Z
        {
            bonusidx[tmpidx] = idx;
            tmpidx++;
        }
        // cout << "bonusidx[tmpidx] : " << bonusidx[tmpidx] << "\t";
        // cout << "tmpidx : " << tmpidx << endl;
        // cout << "tmpidx : " << tmpidx << endl;
    }

    for (int i = 0; i < bonusidx.size(); i++)
    {
        // cout << "bonus idx arr : " << bonusidx[i] << endl; //4 == EOT
        // cout << "int value : " << i << endl;
        // cout << "numdart[bonusidx] : " << numdart[bonusidx[i]];
        switch (numdart[bonusidx[i]])
        {
        case 83:                                                                  //S
            if (numdart[bonusidx[i] - 1] >= 49 && numdart[bonusidx[i] - 1] <= 57) // 1의자리가 1~9
            {
                calcBonus[i] = pow(numdart[bonusidx[i] - 1] - 48, 1);
            }
            else if (numdart[bonusidx[i] - 1] == 48 && numdart[bonusidx[i] - 2] == 49 && numdart[bonusidx[i] - 2] != 48) //10일 경우
            {
                calcBonus[i] = 10;
            }
            else
            {
                calcBonus[i] = 0;
            }

            break;
        case 68:                                                                  //D
            if (numdart[bonusidx[i] - 1] >= 49 && numdart[bonusidx[i] - 1] <= 57) // 1의자리가 1~9
            {
                calcBonus[i] = pow(numdart[bonusidx[i] - 1] - 48, 2);
            }
            else if (numdart[bonusidx[i] - 1] == 48 && numdart[bonusidx[i] - 2] == 49 && numdart[bonusidx[i] - 2] != 48) //10일 경우
            {
                calcBonus[i] = 100;
            }
            else
            {
                calcBonus[i] = 0;
            }
            break;
        case 84:                                                                  //T
            if (numdart[bonusidx[i] - 1] >= 49 && numdart[bonusidx[i] - 1] <= 57) // 1의자리가 1~9
            {
                calcBonus[i] = pow(numdart[bonusidx[i] - 1] - 48, 3);
            }
            else if (numdart[bonusidx[i] - 1] == 48 && numdart[bonusidx[i] - 2] == 49 && numdart[bonusidx[i] - 2] != 48) //10일 경우
            {
                calcBonus[i] = 1000;
            }
            else
            {
                calcBonus[i] = 0;
            }
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < calcBonus.size(); i++)
    {
        switch (numdart[bonusidx[i] + 1])
        {
        case 42: //*
            if (i == 0)
            {
                calcBonus[i] = calcBonus[i] * 2;
            }
            else
            {
                calcBonus[i] = calcBonus[i] * 2;
                calcBonus[i - 1] = calcBonus[i - 1] * 2;
            }

            break;
        case 35: //#
            calcBonus[i] *= (-1);
            break;
        default:
            break;
        }
    }
    for (int j = 0; j < calcBonus.size(); j++)
    {
        answer += calcBonus[j];
        // cout << calcBonus[j] << " ";
    }

    // cout << endl
    //      << "calcBonus size : " << calcBonus.size() << endl;

    cout << "Answer : " << answer << endl;

    return 0;
}
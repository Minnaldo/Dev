#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    string dartResult = "1S2D*3T";

    int answer = 0;
    int id = 0;
    int id2 = 0;

    vector<int> score(dartResult.size());
    vector<string> strVec(dartResult.size());
    vector<int> tmp(3, 0);

    for (int i = 0; i < dartResult.size(); i++)
    {
        strVec[i] += dartResult[i];
        score[i] = atoi(strVec[i].c_str());
    }

    for (int i = 0; i < dartResult.size(); i++)
    {
        int idx = 0;

        if (i < 3)
        {
            idx = 0;
        }
        else if (i >= 3 && i < 7)
        {
            idx = 1;
        }
        else
        {
            idx = 2;
        }

        if (strVec[i] == "S")
        {
            id = 1;
        }
        else if (strVec[i] == "D")
        {
            id = 2;
        }
        else if (strVec[i] == "T")
        {
            id = 3;
        }

        switch (id)
        {
        case 1: //S
            if (score[i - 1] != 0)
            {
                tmp[idx] = pow(score[i - 1], 1);
            }
            else
            {
                tmp[idx] = pow(10, 1);
            }
            break;
        case 2: //D
            if (score[i - 1] != 0)
            {
                tmp[idx] = pow(score[i - 1], 2);
            }
            else
            {
                tmp[idx] = pow(10, 2);
            }
            break;
        case 3: //T
            if (score[i - 1] != 0)
            {
                tmp[idx] = pow(score[i - 1], 3);
            }
            else
            {
                tmp[idx] = pow(10, 3);
            }
            break;
        default:    
            break;
        }

        if (strVec[i] == "*")
        {
            id2 = 1;
        }
        else if (strVec[i] == "#")
        {
            id2 = 2;
        }

        switch (id2)
        {
        case 1: //*
            tmp[idx] *= 2;
            tmp[idx - 1] *= 2;
            break;
        case 2: //#
            tmp[idx] *= (-2);
            break;
        default:    //
            tmp[idx] *= 1;
            break;
        }
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        answer += tmp[i];
    }
    cout << answer << endl
         << "END";

    return 0;
}

int tmpidx = 0;
    for (int  = 0; a < numdart.size(); a++)
    {
        if (numdart[a] >= 65 && numdart[a] <= 90)
        {
            bonusidx[tmpidx] = a;
        }
        
        cout<<"numdart[a] : "<<numdart[a]<<"\t" << "bonusidx[tmpidx] : " << bonusidx[tmpidx] << "\t";
        cout << "tmpidx : " << tmpidx << endl;
        tmpidx++;
    }

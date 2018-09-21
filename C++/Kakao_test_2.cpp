#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 4;
    vector<int> stages = {4, 4, 4, 4, 4};
    vector<int> answer;
    vector<float> tmparr(n);
    vector<float>::iterator itr;

    int totalUser = stages.size();
    int tmpuser = 0;

    for (int j = 1; j <= n; j++)
    {
        int tmp = count(stages.begin(), stages.end(), j);
        float ftmp = (float)tmp;
        float fuser = (float)totalUser;
        if (ftmp != 0)
        {
            tmparr[j - 1] = (ftmp / fuser);
            totalUser = totalUser - tmp;
        }
        else
        {
            tmparr[j-1] = 0.0;
            totalUser = totalUser - tmp;
        }
    }

    for (int i = 0; i < tmparr.size(); i++)
    {
        cout << i + 1 << "번 스테이지 실패율 : " << tmparr[i] << endl;
    }
    cout << endl;

    while (true)
    {
        if (*(max_element(tmparr.begin(), tmparr.end())) == -1)
        {
            break;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                auto itr = max_element(tmparr.begin(), tmparr.end()); //itr반환형
                if (tmparr[i] == *itr && *itr != -1)
                {
                    cout<<"itr : " << *itr << "\t";
                    answer.push_back(i + 1);
                    *itr = -1;
                }
            }
        }
    }
    
    cout << "Answer size : " << answer.size() << endl;
    cout << "tmparr size : " << tmparr.size() << endl;

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << "\t";
    }

    return 0;
}
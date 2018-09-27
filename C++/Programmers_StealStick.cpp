#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string arrangement = "()(((()())(())()))(())";
    int answer = 0;
    vector<int> lazor, stick, strV;
    //레이저 찾기 : 가장 작은 괄호쌍
    //쇠막대 찾기 : 가장 작은 괄호쌍을 제외한 괄호의 쌍

    for (int i = 0; i < arrangement.size(); i++)
    {
        if (arrangement.at(i) == '(')
        {
            strV.push_back(3);
        }
        else
        {
            strV.push_back(4);
        }
    }

    cout << "strV : "
         << "  ";

    for (int i = 0; i < strV.size(); i++)
    {
        cout << strV.at(i) << "  ";
    }
    cout << endl;
    cout << "strV size : " << strV.size() << endl;

    for (int i = 0; i < strV.size(); i++)
    {
        if (strV[i] == 3 && strV[i + 1] == 4)
        {
            lazor.push_back(i);
            lazor.push_back(i + 1);
            strV.at(i) = 0;
            strV.at(i + 1) = 0;
        }
    }

    
    for(int i = 0; i < lazor.size(); i++)
    {
        lazor.at(i);
    }
    

    cout << "Lazor location : "
         << "  ";
    for (int i = 0; i < lazor.size(); i++)
    {
        cout << lazor.at(i) << "  ";
    }
    cout << endl;

    cout << "Stick location : " << endl;
    for (int i = 0; i < stick.size(); i++)
    {
        cout << stick.at(i) << "  ";
    }
    cout << endl;

    return 0;
}

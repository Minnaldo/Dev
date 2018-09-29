#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*TODO: 다른방법이 있을듯
    레이저 위치 기준으로 괄호 수 세서 * 2;
    속도를 더 빠르게
*/
int main()
{
    string arrangement = "()(((()())(())()))(())";

    int answer = 0;

    auto itr = arrangement.begin();

    // 레이저 위치 표시
    while (itr != arrangement.end())
    {
        if (*itr == '(' && *(itr + 1) == ')')
        {
            *itr = '0';
            arrangement.erase(itr + 1);
        }
        itr++;
    }
    int condition = 1;
    while (condition)
    {
        auto tmpitr = find(arrangement.begin(), arrangement.end(), ')');
        if (tmpitr != arrangement.end())
        {
            for (auto fositr = tmpitr-1; fositr >= arrangement.begin(); fositr--)
            {
                if (*fositr == '(')
                {
                    
                    int tmpSteal = count(fositr, tmpitr, '0');
                    if (tmpSteal > 0)
                    {
                        tmpSteal += 1;
                    }
                    
                    answer += tmpSteal;
                    arrangement.erase(tmpitr);
                    arrangement.erase(fositr);
                    break;
                }
            }
        }else{
            condition = 0;
            arrangement.clear();
        }
    }


    for (int i = 0; i < arrangement.size(); i++)
    {
        cout << arrangement.at(i);
    }
    cout << endl;

    cout << "Answer : " << answer << endl;
    return 0;
}

#include <chrono>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices);

int main(int argc, char const *argv[])
{
    vector<int> prices = {498, 501, 470, 489};
    vector<int> print;
    print = solution(prices);

    for (int i = 0; i < print.size(); i++)
    {
        cout << print[i] << " ";
    }
    cout << endl;

    return 0;
}

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int pSize = prices.size();

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < pSize; i++)
    {

        if (i == pSize - 1)
        {
            answer.push_back(0);
        }
        for (int j = i + 1; j < pSize; j++)
        {
            if (prices.at(i) > prices.at(j))
            {
                answer.push_back(j - i);
                break;
            }
            else
            {
                if (j == pSize - 1 && i != pSize - 1)
                {
                    answer.push_back(pSize - i - 1);
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    
    cout<<"Code Duration : "<< (float)(end-start).count() / CLOCKS_PER_SEC<<endl;
    return answer;
}
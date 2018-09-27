#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> answer;
    vector<int> healths = {200, 120, 150};
    vector<vector<int>> items({
        vector<int>({30, 100}),
        vector<int>({500, 30}),
        vector<int>({100, 400}),
    });
    vector<int> tmpAtk;

    stable_sort(items.begin(), items.end());     //1번째 원소 기준 정렬 (공격력 기준)
    stable_sort(healths.begin(), healths.end()); //체력순 오름차순 정렬
    reverse(items.begin(), items.end());
    reverse(healths.begin(), healths.end());

    for (int i = 0; i < items.size(); i++)
    {
        for (int j = 0; j < items[i].size(); j++)
        {
            cout << items[i].at(j) << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < healths.size(); i++)
    {
        int tmp = healths.at(i) - items.back().at(1);
        if (tmp < 100)
        { //아이템 채택 불가
            break;
        }
        else
        {                                         //아이템 채택 가능
            answer.push_back(items.back().at(0)); //tmpAtk 에 공격력값 추가
            items.pop_back();
        }
    }

    cout<<endl<<endl;
    stable_sort(answer.begin(), answer.end()); //answer 오름차순 정렬
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << endl;
    }
    return 0;
}

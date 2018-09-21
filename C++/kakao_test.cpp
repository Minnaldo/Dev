#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    vector<string> answer;
    vector<string>::iterator tmpitr;
    int logSize = record.size();

    vector<vector<string>> nickname(record.size(), vector<string>(2));

    vector<string> tmp;
    string buf;

    int idx = 0;
    int ansIdx = 0;

    //record 분할
    for (int i = 0; i < logSize; i++)
    {
        stringstream ss(record.at(i));
        while (ss >> buf)
        {
            tmp.push_back(buf);
        }
    }
    vector<string>::iterator itr = tmp.begin(); // itr이 tmp 첫요소 가리킴
    while (itr != tmp.end())
    {
        //uid는 0번배열 name은 1번 배열
        if (*itr == "Enter")
        {
            cout << "Enter" << endl;
            nickname[idx][0] = *(++itr); //uid
            nickname[idx][1] = *(++itr); //nickname

            cout << nickname[idx][1] << "님이 들어왔습니다" << endl;
            answer.push_back(nickname[idx][0]);
            answer.push_back("님이 들어왔습니다");

            if (find(answer.begin(), answer.end(), nickname[idx][0]) != answer.end())
            {
                for (int j = 0; j < answer.size(); j++)
                {

                    { //answer에서 uid가 중복되는걸 찾았을 때
                        tmpitr = find(answer.begin(), answer.end(), nickname[idx][0]);
                        *tmpitr = nickname[idx][1];
                    }
                }
            }
        }
        else if (*itr == "Leave")
        {
            string tmpname = "";
            cout << "Leave" << endl;
            itr++; // == uid
            for (int i = 0; i < idx; i++)
            {
                if (nickname[i][0] == (*itr))
                {
                    tmpname += nickname[i][1];
                }
            }
            cout << tmpname << "님이 나갔습니다" << endl;
            answer.push_back(*itr);
            answer.push_back("님이 나갔습니다");
        }
        else if (*itr == "Change")
        {
            cout << "Chagne" << endl;
            nickname[idx][0] = *(++itr);
            nickname[idx][1] = *(++itr);
            tmpitr = find(answer.begin(), answer.end(), nickname[idx][0]);
            for (int j = 0; j < answer.size(); j++)
            {
                *tmpitr = nickname[idx][1];
            }
        }
        else
        {
            break;
        }
        idx++;
        itr++;
    }
    cout << endl
         << endl
         << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << endl;
    }
}

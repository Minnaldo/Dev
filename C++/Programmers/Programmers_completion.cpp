#include <algorithm>
#include <iostream>
#include <hash_map>
#include <map>
#include <string>
#include <vector>

/**
 *
 */

using namespace std;

string Soltuion(vector<string> participant, vector<string> completion)
{
    string answer = "";

    map<string, bool> map1;

    int size = completion.size();
    for (int i = 0; i < size; i++)
        map1.insert(make_pair(completion[i], true));

    auto itr = participant.begin();
    for (itr; itr !=  participant.end(); itr++)
    {
        if(map1[*itr] == NULL){
            answer = *itr;
            break;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string Solution();
    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> people, tshirts;
    int answer = 0;
    int len = 0;

    people = {2, 3};
    tshirts = {1, 2, 3};

    if(people.size() > tshirts.size())
    {
         len = people.size();
    }else{
         len = tshirts.size();
    }

    stable_sort(people.begin(), people.end());
    stable_sort(tshirts.begin(), tshirts.end());
    reverse(people.begin(), people.end());
    reverse(tshirts.begin(), tshirts.end());

    for(int i = 0; i<len; i++){
        if(people.back() <= tshirts.back()){
            answer++;
            people.pop_back();
            tshirts.pop_back();
        }else{
            tshirts.pop_back();
        }
    }

    cout << "Answer : " << answer << endl;

    return 0;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    
    for(int i = 0; i < phone_book.size()-1; i++)
    {
        for(int j = 0; j<phone_book[i].size(); j++)
        {
            if(phone_book[i][j] != phone_book[i+1][j])
            {
                break;
            }
            else if(phone_book[i].size() -1 == j && phone_book[i][j] == phone_book[i+1][j])
            {
                return false;
            }
        }
    }
    
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> phone_book1 = {"12232332", "12", "222222"};
    vector<string> phone_book2 = {"911", "97625999", "91125426"};
    vector<string> phone_book3 = {"113", "12340", "123440", "12345", "98346"};

    // sort(phone_book1.begin(), phone_book1.end());

    // cout << solution(phone_book1) << endl;
    // cout << solution(phone_book2) << endl;
    // cout << solution(phone_book3) << endl;
    return 0;
}

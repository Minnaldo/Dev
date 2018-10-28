#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//문자 외에 기호 삭제 및 소문자로 변환
string oper_Del(string arr)
{
    string result = "";
    auto itr = arr.begin();
    int Arr_Size = arr.size();

    for (int i = 0; i < Arr_Size; i++)
    { //문자만 result 벡터에 저장
        if (*itr >= 97 && *itr <= 122 && *itr >= 65 && *itr <= 90)
        {
            result += *itr;
        }
    }
    //result 벡터 소문자 변환
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int solution(string str1, string str2)
{
    vector<string> inter_set, union_set, subset1, subset2;

    string arr1 = oper_Del(str1);
    string arr2 = oper_Del(str2);
    auto itr1 = arr1.begin();
    auto itr2 = arr2.begin();

    while (itr1 != arr1.end() && itr2 != arr2.end())
    {
        if ((itr1 + 1) != arr1.end() && (itr2 + 1) != arr2.end())
        {
            string tmp1, tmp2;
            tmp1 = *itr1 + *(itr1 + 1);
            tmp2 = *itr2 + *(itr2 + 1);
            subset1.push_back(tmp1);
            subset2.push_back(tmp2);
        }
        itr1++;
        itr2++;
    }

    auto inter_itr = set_intersection(subset1.begin(), subset1.end(), subset2.begin(), subset2.end(), inter_set.begin());
    auto union_itr = set_union(subset1.begin(), subset1.end(), subset2.begin(), subset2.end(), union_set.begin());

    int ans = ((inter_itr - inter_set.begin()) / (union_itr - union_set.begin())) * 65536;

    return ans;
}

int main(int argc, char const *argv[])
{
    string str1 = "FRANCE";
    string str2 = "french";

    cout << solution(str1, str2) << endl;
}
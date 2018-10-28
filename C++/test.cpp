#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/** https://programmers.co.kr/learn/courses/30/lessons/17677
 * * 뉴스 클러스터링
 */

//문자 외에 기호 삭제 및 소문자로 변환
string oper_Del(string arr)
{
    string result = "";
    auto itr = arr.begin();
    int tmp = 0;

    for (itr; itr < arr.end(); itr++)
    { //문자만 result 벡터에 저장, char to int 변환
        tmp = *itr - '\0';
        if ((tmp >= 97 && tmp <= 122) || (tmp >= 65 && tmp <= 90))
        {
            result += *itr;
        }
    }
    //result 벡터 소문자 변환
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

vector<string> makeSet(string str)
{
    vector<string> strVec;
    auto itr = str.begin();
    int strSize = str.size() - 1;
    for (int i = 0; i < strSize; i++)
    {
        string tmp = "";
        tmp += str[i];
        tmp += str[i + 1];
        strVec.push_back(tmp);
    }

    return strVec;
}

vector<string> make_Intersection(vector<string> t, vector<string> p)
{
    int size = t.size();
    int size2 = p.size();
    vector<string> result;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (t[i] == p[j])
            {
                result.push_back(p[j]);
            }
        }
    }

    return result;
}

vector<string> make_Union(vector<string> t, vector<string> p)
{
    vector<string> result;
    result.assign(t.begin(), t.end());

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            if (result[i] != p[j])
            {
                result.push_back(p[j]);
            }
        }
    }

    return result;
}

int solution(string str1, string str2)
{
    vector<string> inter_set, union_set, subset1, subset2;

    string arr1 = oper_Del(str1);
    string arr2 = oper_Del(str2);

    subset1 = makeSet(arr1);
    subset2 = makeSet(arr2);

    inter_set = make_Intersection(subset1, subset2);
    union_set = make_Union(subset1, subset2);

    // int vecSize = subset1.size() + subset2.size();
    // inter_set = make_Intersection(subset1, subset2);
    // union_set = make_Union(subset1, subset2);
    // inter_set.resize(vecSize);
    // union_set.resize(vecSize);
    // auto inter_itr = set_intersection(subset1.begin(), subset1.end(), subset2.begin(), subset2.end(), inter_set.begin());
    // auto union_itr = set_union(subset1.begin(), subset1.end(), subset2.begin(), subset2.end(), union_set.begin());

    // inter_set.resize(inter_itr - inter_set.end());
    // union_set.resize(union_itr - union_set.end());

    float inter_size = (float)inter_set.size();
    float union_size = (float)union_set.size();
    float dvide = inter_size / union_size;

    int ans = (int)(dvide * 65536.0);
    return ans;
}

int main(int argc, char const *argv[])
{
    string str1 = "FRANCE";
    string str2 = "french";

    cout << solution(str1, str2) << endl;
}
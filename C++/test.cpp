#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/** https://programmers.co.kr/learn/courses/30/lessons/17677
 * * 뉴스 클러스터링
 */

//문자 외에 기호 삭제 및 소문자로 변환
vector<string> oper_Del(vector<string> strVec)
{ //집합 내 문자가 아닌 원소를 찾아 지운다.
    int size = strVec.size();
    //문자만 result 벡터에 저장, char to int 변환

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int tmp = strVec[i][j] - '\0';
            if (!((tmp >= 97 && tmp <= 122) || (tmp >= 65 && tmp <= 90)))
            {
                strVec[i] = "";
            }
            else
            {
                //result 벡터 소문자 변환
                tolower(strVec[i][j]);
            }
        }
    }
    auto itr = strVec.begin();
    while (itr != strVec.end())
    {
        itr = find(strVec.begin(), strVec.end(), "");
        if (itr != strVec.end())
        {
            strVec.erase(itr);
        }
    }

    return strVec;
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

    int size = p.size();
    vector<string> result;
    result.clear();
    auto itr = p.begin();
    for (int j = 0; j < size; j++)
    {

        if (find(t.begin(), t.end(), p[j]) != t.end())
        {
            result.push_back(p[j]);
        }
    }

    return result;
}

vector<string> make_Union(vector<string> t, vector<string> p)
{
    int size = p.size();
    vector<string> result;
    result.assign(t.begin(), t.end());
    for (int i = 0; i < size; i++)
    {
        if (find(result.begin(), result.end(), p[i]) == result.end())
        {
            result.push_back(p[i]);
        }
    }

    return result;
}

int solution(string str1, string str2)
{
    vector<string> inter_set, union_set, subset1, subset2;

    subset1 = makeSet(str1);
    subset2 = makeSet(str2);
    sort(subset1.begin(), subset1.end());
    sort(subset2.begin(), subset2.end());

    subset1 = oper_Del(subset1);
    subset2 = oper_Del(subset2);

    inter_set = make_Intersection(subset1, subset2);
    union_set = make_Union(subset1, subset2);

    float inter_size = (float)inter_set.size();
    float union_size = (float)union_set.size();
    float dvide = inter_size / union_size;

    int ans = (int)(dvide * 65536.0);
    return ans;
}

int main(int argc, char const *argv[])
{
    string str1 = "aa1+aa2";
    string str2 = "AAAA12";

    cout << solution(str1, str2) << endl;
}
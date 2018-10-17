#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

/**
 * BFS를 이용, 최단거리 찾는 방법을 응용한다
 * 인접 노드 : 현재문자와 다른 문자가 하나만 있는 문자
 * Traget이 배열 내에 없으면 바로 0 리턴
*/

stack<string> s;
queue<string> q;
bool visit[50];
vector<string> cpStr(50);
int pos, strLength, depthCnt;
vector<int> len;

bool stringRecog(string front, string word)
{
    int strChk = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (front[i] != word[i])
        {
            strChk++;
        }
    }

    if (strChk < 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(string curStr, string cmpStr)
{
    visit[i] = true;
    for (int i = 0; i < strLength; i++)
    {
        if (!visit[i] && stringRecog(curStr, cmpStr))
        {
            depthCnt++;
            dfs(s.top(), cpStr[i]);
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    cpStr.assign(words.begin(), words.end());
    int answer = 0;
    strLength = cpStr.size();

    if (find(cpStr.begin(), cpStr.end(), target) != cpStr.end()) //target word가 words 배열 안에 있음
    {
        // q.push(begin);
        s.push(begin);
        len.push_back(0);

        for (int i = 0; i < strLength; i++)
        {
            if (!visit[i])
            {
                visit[i] = true;
                dfs(begin, cpStr[i]);
            }
        }
    }
    else
    {
        answer = 0;
    }
    return answer;
}

int main()
{
    vector<string> arr = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> arr2 = {"hot", "dot", "dog", "lot", "log"};
    string begin = "hit";
    string target = "cog";
    cout << "resutl 1 : " << solution(begin, target, arr) << endl;
    cout << "resutl 2 : " << solution(begin, target, arr2) << endl;

    return 0;
}
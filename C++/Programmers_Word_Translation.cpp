#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

/**
 * BFS를 이용, 최단거리 찾는 방법을 응용한다
 * 인접 노드 : 현재문자와 다른 문자가 하나만 있는 문자
 * Traget이 배열 내에 없으면 바로 0 리턴
*/

queue<string> q;
vector<int> len; //거쳐온 단어 갯수 저장 배열
bool visit[50];  //방문 확인 배열
int pos, strLength;

bool strCompare(string front, string word)
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

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    strLength = words.size();
    string tmpStr;

    if (find(words.begin(), words.end(), target) != words.end()) //target word가 words 배열 안에 있음
    {
        q.push(begin);
        len.push_back(0);

        while (!q.empty())
        {
            for (int j = 0; j < strLength; j++)
            {
                if (!visit[j] && strCompare(q.front(), words[j]))
                {
                    q.push(words[j]);
                    visit[j] = true;
                    len.push_back(len[pos] + 1);
                }
            }
            tmpStr = q.front();
            q.pop();
            pos++;
        }

        if (target == tmpStr)
        { 
            answer = len.back();
        }
        else
        {
            answer = 0;
        }
    }
    else //target word 가 wods배열 안에 없을 때
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
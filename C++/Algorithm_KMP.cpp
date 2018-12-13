#include <iostream>
#include <vector>

using namespace std;

/** * KMP알고리즘 구현해보기
 *  * 문자열 매칭 알고리즘
 * TODO
 */

//  KMP pre-processing
vector<int> preProcessing(string pattern)
{
    int i = 0, j = -1;
    vector<int> next;
    int pSize = pattern.size();
    next.assign(pSize, -1);
    while (i < pSize)
    {
        while (j >= 0 && pattern[i] != pattern[j])
        {
            next[j] = j;
        }

        i++;
        j++;
        next[i] = j;
    }

    return next;
}

vector<int> KMP(string pattern, string plainText)
{
    int i = 0, j = 0;
    int pTextSize = plainText.size();
    auto next = preProcessing(pattern);
    vector<int> answer;
    while (i < pTextSize)
    {
        while (j >= 0 && (pattern[j] != plainText[i]))
        {
            next[j] = j;
        }
        i++;
        j++;
        if (j == pTextSize)
        {
            next[j] = j;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{

    return 0;
}
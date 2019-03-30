#include <iostream>
#include <vector>

using namespace std;

/** * KMP알고리즘 구현해보기
 *  * 문자열 매칭 알고리즘
 *  * 일치하는 갯수와 일치하는 위치를 반환하자
 * TODO
 */

//  KMP pre-processing
//  접두사와 접미사의 최대 일치길이를 구한다.
//  i인덱스와 j인덱스의 문자열이 같으면 둘 다 증가, 아니면 i만 증가
vector<int> preProcessing(string pattern)
{
    int j = 0; // j ==> 접두사의 길이 인덱스
    int pSize = pattern.size();
    vector<int> fail(pSize, 0); // 실패함수 초기화, 점프할 칸의 수를 저장할 배열의 크기는 패턴의 크기와 같다.

    //  i는 왜 1에서부터 시작을 해야하나??
    //  i와 j가 같으면, 모든 문자열을 검사하게 되므로, 알고리즘이 의미가 없다
    for (int i = 1; i < pSize; i++)
    {
        while (j > 0 && (pattern[i] != pattern[j])) // j인덱스의 문자와 i인덱스 문자가 다를 때
        {
            j = fail[j - 1]; // 비교한 문자열이 다를경우 실패함수에 이전 인덱스의 값을 j 값으로 한다
        }

        // 일치시, j인덱스의 값에 1을 더해 실패함수에 저장
        if (pattern[j] == pattern[i])
            fail[i] = ++j; // j++, fail[i] = j;
    }

    return fail;
}

vector<int> KMP(string plainText, string pattern)
{
    int j = 0;
    int pTextSize = plainText.size();
    int patternSize = pattern.size();
    vector<int> fail = preProcessing(pattern);
    vector<int> answer;
    for (int i = 0; i < pTextSize; i++)
    {
        while (j > 0 && pattern[j] != plainText[i])
            j = fail[j - 1];

        if (plainText[i] == pattern[j])
            if (j == patternSize - 1)
            {
                printf("%d번재에서 찾았습니다.\n", i - patternSize + 2);
                j = fail[j];
            }
            else
                j++;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string str = "ABCEDABCEFQJDNVABRIDFNIABC";
    string pattern = "abacaaba";

    vector<int> ans = preProcessing(pattern);
    // vector<int> ans = KMP(str, pattern);

    int size = ans.size();
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
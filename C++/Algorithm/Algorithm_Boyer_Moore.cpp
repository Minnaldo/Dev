#include <iostream>
#include <string>

using namespace std;

/** 보이어 무어 알고리즘 문자열 매칭 알고리즘 ( BM알고리즘 )
 *  * BCS (BadCharacter Shift Rule)을 이용할 수 없으면 GSS (Good Suffix Shift Rule)을 이용한다
 */

int table[26];

int *bcTable(string pattern)
{
    int pSize = pattern.size();

    for (int i = 0; i < pSize; i++)
    {
        // 테이블을 만든다
    }
}

void badCharacterShiftRule(string pattern, string text)
{
    int pSize = pattern.size();
    int idx = pSize, tSize = text.size();

    while (idx < tSize)
    {
        for (int i = pSize; i > 0; i--)
        {
            if (pattern[i] != text[idx])
            {
                // 패턴내에 현재 문자가 존재하는지 확인 후 없으면 테이블 값 만큼 넘어간다
            }
            idx--;
        }
    }
}

void goodSuffixShiftRule()
{
}

int main(int argc, char const *argv[])
{

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

/** * KMP알고리즘 구현해보기
 *  * 문자열 매칭 알고리즘
 *  * 일치하는 갯수와 일치하는 위치를 반환하자
 *  TODO
 *  REVIEW 2
 */

//  KMP pre-processing
//  패턴 문자열에서 접두사와 접미사의 최대 일치길이를 구한다.
//  i인덱스와 j인덱스의 문자열이 같으면 둘 다 증가, 아니면 i만 증가
//  fail[index]의 value 만큼 일치를 했다. 일치하는 접두사, 접미사의 길이가 fail[idx]의 값 만큼이다.
vector<int> preProcessing(string pattern)
{
    int j = 0; // j ==> 접두사의 길이 인덱스
    int pSize = pattern.size();
    vector<int> fail(pSize, 0); // 실패함수 초기화, 점프할 칸의 수를 저장할 배열의 크기는 패턴의 크기와 같다.
    // 실패함수 (failure function) f[q] = MAX{k:k<q, P[0~k]가 P[0~q]의 접미어가 되는 k}

    //  i는 왜 1에서부터 시작을 해야하나??
    //  i와 j가 같으면, 모든 문자열을 검사하게 되므로, 알고리즘이 의미가 없다

    int i = 1;
    while (i < pSize)
    {
        // 같지 않을때, j(접두사 인덱스)를 줄여가며, j가 0이 아니고 pattern[i] == pattern[j] 일때까지 줄여간다.
        while (j > 0 && (pattern[i] != pattern[j]))
            j = fail[j - 1];

        if (pattern[j] == pattern[i])
        {
            // 현재 j인덱스에 1을 더한 값을 fail함수의 값으로 쓴다(j의 인덱스가 최대 일치길이, j가 0부터 시작이기 때문에 1을 더해준다)
            // j는 이전 문자의 실패함수 값, 실패함수 값이 계속 증가한다면 일치하는 접미사가 있는 접두사의 길이가 증가한다는 뜻
            fail[i] = ++j; // fail[i] = j+1; j++;
        }
        i++;
    }

    return fail;
}

vector<int> KMP(string body, string pattern)
{
    int j = 0; // 패턴의 인덱스
    int bodySize = body.size();
    int patternSize = pattern.size();
    vector<int> fail = preProcessing(pattern); // 실패함수를 저장할 배열
    vector<int> answer;                        // 일치하는 위치의 시작 인덱스를 저장할 배열

    int i = 0; // 본문의 인덱스
    while (i < bodySize)
    {
        // 패턴과 본문이 다른 인덱스를 찾는다
        while (j > 0 && body[i] != pattern[j]) // 패턴과 문자열이 다를 때
            j = fail[j - 1];                   // j = 패턴의 인덱스 pattern[j]부터 다시 찾기 시작한다.

        if (body[i] == pattern[j]) // 본문과 패턴의 문자가 일치할 때
        {
            if (j == patternSize - 1) // j는 0부터 시작, if 문을 만족할 경우 본문에서 패턴과 일치하는 부분을 찾은게 됨
            {
                printf("%d번째에서 찾았습니다.\n", i - patternSize + 2); // 인덱스가 0부터 시작이므로 + 1, 첫 시작부분을 포함해야하므로 또 +1 ==> +2를 해주어야 한다
                j = fail[j];                                             // 다음 일치 부분을 찾기 위해, 패턴의 인덱스를 다음 최대 일치부분으로 하여 다시 탐색한다.

                answer.push_back(i - patternSize + 2);
            }
            else
            {
                // 실패함수 생성때와 같이, 각 인덱스의 문자열이 일치하면 패턴의 인덱스 또한 증가시켜준다.
                j++;
            }
        }
        i++;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string body = "ababacabacaabacaaba";
    string pattern = "abacaaba";

    vector<int> ans = preProcessing(pattern);
    // vector<int> ans = KMP(body, pattern);

    int size = ans.size();
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
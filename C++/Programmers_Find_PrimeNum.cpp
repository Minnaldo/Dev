#include <vector>
#include <string>
#include <iostream>

using namespace std;

/** 소수찾기 (https://programmers.co.kr/learn/courses/30/lessons/42839)
 * *
*/

vector<int> pNum; //소수를 저장할 배열

//N은 자릿수, N자리 수 까지의 소수를 찾는다
//에라토스테네스의 체 이용
void findPrimeNum(int N)
{
    for (int i = 0; i < N; i++)
    {
        pNum[i] = i + 1;
    }
    pNum[0] = 0;

    for (int i = 2; i <= N; i++)
    {
        if (pNum[i - 1] != 0)
        {
            for (int j = i * 2; j <= N; j += i) //i만큼 증가하며 0으로 치환
            {
                pNum[j - 1] = 0;
            }
        }
    }
}

int solution(string numbers)
{

    int N = numbers.size();
    pNum.assign(N, 0);
    findPrimeNum(N);    //N자리 소수까지 pNum에 저장

    //TODO : numbers내의 숫자를 이용한 숫자 조합 찾기
    //소수의 집합에서 numbers 내의 숫자가 포함된 소수 찾기
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j<; j++)
        {
            if(pNum[i] != 0)
            {

            }
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
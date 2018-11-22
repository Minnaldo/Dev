#include <fstream>
#include <iostream>

using namespace std;

/** 계단 오르기 백준온라인저지_2579 (https://www.acmicpc.net/problem/2579)
 *  * 최대값을 구하라
 *  * 계단은 한칸 or 두칸 이동 가능, 3칸연속 불가
 */

int T;         //계단의 수 저장 변수
int memo[301]; //계단의 최대 개수 300개, 0은 시작점

//두 수중 큰 값 반환
int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int *stair) //call by reference
{
    for (int i = 1; i <= T; i++)
    {
        memo[i] = max(memo[i], memo[i - 1] + stair[i]); //1칸 올라갔을 경우
        memo[i] = max(memo[i], memo[i - 2] + stair[i]); //2칸 올라갔을 경우
    }

    return memo[T];
}

int main(int argc, char const *argv[])
{
    cin >> T;
    int *stair = new int[T + 1]; //시작칸은 값이 없음 (시작칸==0)
    // int &ref = *stair;           //생성된 배열 참조변수

    for (int i = 1; i <= T; i++)
    {
        int tmp;
        cin >> tmp;
        stair[i] = tmp;
    }

    cout << solution(stair) << endl; //call by reference;

    delete stair; //Dynamic alloc Array memory return

    return 0;
}
#include <sstream>
#include <iostream>

using namespace std;

/** 계단 오르기 백준온라인저지_2579 (https://www.acmicpc.net/problem/2579)
 *  * Dynamic Programming Problem
 *  ! 최대값을 구하라
 *  * 계단은 한칸 or 두칸 이동 가능, 3칸연속 불가, 마지막 칸은 무조건 밟아야 함
 *  * 점화식 1) memo[i] = memo[i-3] +stair[i-1]+stair[i]    --> 마지막칸에서 3칸전, 1칸 전, 1칸 올라온 경우 (3칸 연속 불가 조건에 따라, 마지막 칸은 무조건 밟아야 함)
 *  *        2) memo[i] = memo[i-2] + stair[i]              --> 마지막칸에서 2칸전, 2칸 올라온 경우 (마지막 칸을 밟아야 한다는 조건)
 *  * 제출.ver 는 iostream --> cstdio
 */

int T;         //계단의 수 저장 변수
int memo[301]; //계단의 최대 개수 300개, 0은 시작점

//두 수중 큰 값 반환
int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(int *stair)
{
    // i는 현재 계단이 몇번 째 인지 나타냄
    for (int i = 3; i <= T; i++) //i는 2부터 ==> 첫번째는 한칸이동 외엔 못밟음
    {
        memo[i] = max(memo[i - 3] + stair[i - 1] + stair[i], memo[i - 2] + stair[i]);
    }

    return memo[T];
}

int main(int argc, char const *argv[])
{
    string buf = "5 2 5 3 2 2";
    stringstream ss;
    int num;
    ss.str(buf);

    ss >> T;
    int *stair = new int[T + 1]; //시작칸은 값이 없음 (시작칸==0)
    // int &ref = *stair;           //생성된 배열 참조변수

    for (int i = 1; i <= T; i++)
    {
        int tmp;
        ss >> tmp;
        stair[i] = tmp;
    }
    stair[0] = 0;
    memo[1] = stair[1];
    memo[2] = max(stair[2] + memo[0], stair[2] + memo[1]);
    cout << solution(stair) << endl;

    delete[] stair; //Dynamic alloc Array memory return
    stair = NULL;   //동적할당배열은 해당 변수 초기화 해줘야함
    return 0;
}
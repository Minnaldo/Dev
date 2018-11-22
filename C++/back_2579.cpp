#include <sstream>
#include <iostream>

using namespace std;

/** 계단 오르기 백준온라인저지_2579 (https://www.acmicpc.net/problem/2579)
 *  ! 최대값을 구하라
 *  * 계단은 한칸 or 두칸 이동 가능, 3칸연속 불가
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
    for (int i = 2; i <= T; i++) //i는 2부터 ==> 첫번째는 한칸이동 외엔 못밟음
    {
        int cnt = 1; //3칸연속 판단 변수
        if (cnt < 3)
        {
            //TODO : 조건을 따로 주자
            memo[i] = max(memo[i], memo[i - 1] + stair[i]); //1칸 올라갔을 경우
            cnt++;
            memo[i] = max(memo[i], memo[i - 2] + stair[i]); //2칸 올라갔을 경우
            i++; //2칸 증가하였으므로 i값도 똑같이 2가 증가하게 해줘야함
            cnt = 1;
        }
        else
        {
            memo[i] = max(memo[i], memo[i - 2] + stair[i]); //2칸 올라갔을 경우
            i++;
            cnt = 1;
        }
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
    memo[1] = stair[1];
    cout << solution(stair) << endl;

    delete[] stair; //Dynamic alloc Array memory return
    stair = NULL;   //동적할당배열은 해당 변수 초기화 해줘야함
    return 0;
}
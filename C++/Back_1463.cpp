#include <iostream>

using namespace std;

<<<<<<< HEAD
int solution(int N, int cnt)
{
    solution(N / 3, ++cnt);
    solution(N / 2, ++cnt);
    solution(--N, ++cnt);

    if (N == 1)
    {
        return cnt;
    }
    else
    {
        return 0;
    }
=======
/** 1로 만들기 백준온라인저지_1463 (https://www.acmicpc.net/problem/1463)
 *  * 문제와 반대로 1->N을 만들수 있는 경우의 수를 찾아 최소연산을 리턴
 */

//메모 배열에 연산 횟수를 더한다
int memo[1000001];

// parameter 두개를 입력받아 작은 걸 반환
// 이문제에서는 더 작은 연산횟수를 반환하기 위함
int min(int a, int b)
{
    return a > b ? b : a;
>>>>>>> 098a6ccd0fa07f3f90a4b52fc380a027ba660bc0
}

int main(int argc, char const *argv[])
{
<<<<<<< HEAD
    cout << solution(10, 0) << endl;
=======
    int N;
    cin >> N;

    // 1부터 시작하기 위해 memo[1]을 시작점으로
    memo[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        memo[i] = memo[i - 1] + 1; // memo[i-1] ==> 의 이유 if i가 memo[i-1]에서 1을 더해 나올 수 있는 수 이므로 연산을 하고 연산횟수 1을 더해준다
        if (i % 2 == 0)
        {
            memo[i] = min(memo[i], memo[i / 2] + 1); // memo[i/2] ==> 의 이유 if i가 2의 배수 일때 i/2에서 2를 곱해 나올수 있는 수 이므로
        }
        if (i % 3 == 0)
        {
            memo[i] = min(memo[i], memo[i / 3] + 1); // memo[i/3] ==> 의 이유 if i가 3의 배수 일때 i/3에서 3를 곱해 나올수 있는 수 이므로
        }
    }

    cout << memo[N] << endl;
>>>>>>> 098a6ccd0fa07f3f90a4b52fc380a027ba660bc0
    return 0;
}
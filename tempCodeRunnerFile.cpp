<<<<<<< HEAD
=======
#include <vector>
>>>>>>> 098a6ccd0fa07f3f90a4b52fc380a027ba660bc0
#include <iostream>

using namespace std;

<<<<<<< HEAD
int solution(int N)
{
    int cnt = 0;
    if((N%3) == 0)
    {
        N/=3;
        cnt++;
    }
    else if((N%2) == 0)
    {
        N/=2;
        cnt++;
    }
    else
    {
        N--;
        cnt++;
    }

    return cnt;
=======
int memo[1000001];

int min(int a, int b)
{
    return a>b ? b:a;
>>>>>>> 098a6ccd0fa07f3f90a4b52fc380a027ba660bc0
}

int main(int argc, char const *argv[])
{
<<<<<<< HEAD
    cout<<solution(10)<<endl;
=======
    int N;
    cin>>N;

    memo[1] = 0;

    for(int i = 2; i<=N; i++)
    {
        memo[i] = memo[i-1] +1;
        if(i%2 == 0)
        {
            memo[i] min(memo[i], memo[i/2]+1);
        }
        if(i%3 == 0)
        {
            memo[i] = min(memo[i], memo[i/3] +1);
        }
    }

    cout<<memo[N]<<endl;
>>>>>>> 098a6ccd0fa07f3f90a4b52fc380a027ba660bc0
    return 0;
}
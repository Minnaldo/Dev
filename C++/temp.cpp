#include <iostream>

using namespace std;

int solution(int n)
{
    int cycle, pre;

    while(true)
    {
        if(n<0){

        }

        cycle++;
    }
}

int main(int argc, char const *argv[])
{
    int C;
    cin>>C;
        cout.precision(3);

    for(int i = 0; i<C; i++)
    {
        int N, sum, cnt;
        cin>>N;
        int* arr = new int [N];

        for(int j =0; j<N;j++)
        {
            int tmp;
            cin>>tmp;
            arr[j] = tmp;
            sum += arr[j];
        }

        float avg = (float)(sum/N);

        for(int j = 0; j<N; j++)
        {
            if(arr[j] > avg) cnt++;
        }

        cout<<(float)(cnt/N)*100<<endl;

    }
    return 0;
}
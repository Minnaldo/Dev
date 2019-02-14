#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/**
 *  DFS와 BackTracking을 조합하여 판단
 *  매 분기마다 +연산과 -연산을 해야함 
 */

int graph[20][20];

int backtrack(int target, vector<int> numbers)
{
    int cnt = 0;
    int vecSize = numbers.size();

    for(int i=0; i<vecSize; i++)
    {
        for(int j = 0; j<vecSize; j++)
        {
            graph[i][i+1] = graph[i+1][i] = numbers[j];
        }
    }

    for(int i = 0; i<vecSize; i++)
    {
        for(int j = 0; j<vecSize; j++)
        {
            cout<< graph[i][j]<<" ";
        }
        cout<<endl;
    }
        

        // if (currentSum == target)
        // {
        //     cnt++;
        // }

    return cnt;
}

int main()
{
    vector<int> numbers = {1, 1, 1,1,1,1};
    int target = 3;

    cout << backtrack(target, numbers) << endl;
    return 0;
}
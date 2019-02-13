#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool chk[1000001];

int DFS(vector<int> &A, int start)
{
    stack<int> st;
    st.push(start);
    chk[start] = true;

    int current = st.top();
    int tmpCount = 0;
    int last = start + 1;

    while (!st.empty())
    {
        if (!chk[A[current]])
        {
            st.push(A[current]);
            chk[st.top()];
        }

        current = st.top();
        st.pop();
        tmpCount++;
    }

    return tmpCount;
}

int solution(vector<int> &A)
{
    int answer = 0;
    int arrSize = A.size();

    for (int i = 0; i < arrSize; i++)
    {
        if (!chk[i])
        {
            int count = DFS(A, i);

            if (answer < count)
            {
                answer = count;
            }
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {5, 4, 0, 3, 1, 6, 2};  // 4
    vector<int> A1 = {1, 2, 3, 0};          // 4
    vector<int> A2 = {0, 1, 2, 3, 4, 5, 6}; // 1
    vector<int> A3 = {1, 2, 3, 4};          // 0
    vector<int> A4 = {1, 2, 3, 4, 1};       // 0
    vector<int> A5 = {5, 4, 0, 3, 1, 6, 2}; // 4

    int answer = solution(A);
    cout << "Answer :: " << answer << endl;
    return 0;
}

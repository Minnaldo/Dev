#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 후위식을 만들 때는 연산자는 스택에 저장하고, 피연산자는 배열에 저장한다
vector<int> make_postfix(string str, int len)
{
    stack<char> s;
    vector<int> arr;
    auto itr = str.begin();

    for (itr; itr != str.end(); itr++)
    {
        int tmp = *itr - '0';

        // 숫자면 배열에 저장
        if (0 <= tmp && tmp <= 9)
        {
            arr.push_back(*itr - '0');
        }
        else // 숫자가 아닐 때 ==> 기호일 때
        {
            if (*itr == ')')
            {
                while (s.top() != '(')
                {
                    arr.push_back(s.top() - '0');
                    s.pop();
                }
                s.pop();
            }
            else if (*itr == '+')
            {
                if (!s.empty())
                {
                    if (s.top() == '+' || s.top() == '*')
                    {
                        arr.push_back(s.top() - '0');
                        s.pop();
                        s.push(*itr);
                    }
                    else
                    {
                        s.push(*itr);
                    }
                }
                else
                    s.push(*itr);
            }
            else if (*itr == '*')
            {
                if (!s.empty())
                {
                    if (s.top() == '*')
                    {
                        arr.push_back(s.top() - '0');
                        s.pop();
                        s.push(*itr);
                    }
                    else
                    {
                        s.push(*itr);
                    }
                }
                else
                    s.push(*itr);
            }
            else // 무조건 스택에 넣는다. *itr == '('
            {
                s.push(*itr);
            }
        }
    }

    while (!s.empty())
    {
        arr.push_back(s.top()-'0');
        s.pop();
    }

    return arr;
}

// 후위식을 계산할 때에는 피연산자를 스택에 저장하고, 연산자를 만날때마다 데이터 두개를 꺼내 연산후 다시 삽입한다.
int calc(vector<int> arr)
{
    stack<int> st;
    auto itr = arr.begin();
    for (itr; itr != arr.end(); itr++)
    {
        if (*itr == '+' || *itr == '*')
        {
            // char tmp1 = st.top();
            // st.pop();
            // char tmp2 = st.top();
            // st.pop();

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            if (*itr == '+')
            {
                int sum = op1 + op2;
                // char tmpch = '0' + sum;
                st.push(sum);
            }
            else
            {
                int mul = op1 * op2;
                // char tmpch = '0' + mul;
                st.push(mul);
            }
        }
        else
        {
            st.push(*itr - '\0');
        }
    }
    int ret = st.top();

    return st.top();
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    for (int i = 1; i <= 1; i++)
    {
        int len;
        cin >> len;
        string str;
        cin >> str;

        vector<int> arr = make_postfix(str, len);

        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << endl;
        cout << endl;

        // int ans = calc(arr);
        // printf("#%d %d\n", i, ans);
    }
    return 0;
}
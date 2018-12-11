#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n, string func)
{
    auto itr = arr.begin();
    vector<int> arr2(n, 0);
    auto strItr = func.begin();
    int idx = 0;
    while (func[idx] != ' ')
    {
        if (func[idx] == 'D')
        {
            if (itr == arr.end())
            {
                cout << "error" << endl;
                exit(1);
            }
            else
            {
                *itr = 0;
            }
        }
        else if (func[idx] == 'R')
        {
            auto ritr = arr.rbegin();
            for (int i = 0; i < arr2.size(); i++)
            {
                arr2[i] = *ritr;
                ritr++;
            }
        }
        idx++;
    }

    return arr2;
}

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt");

    int T, n;
    fs >> T;

    for (int i = 0; i < T; i++)
    {
        // string func;
        char func[100];
        // fs >> func; //수행할 케이스
        fs.getline(func,sizeof(func));
        fs >> n;    //배열 크기, 숫자 갯수
        vector<int> arr(n, 0);
        string array; // 숫자들
        getline(cin, array, ',');
        for (int j = 0; j < n; j++)
        {
            int tmp;
            fs >> tmp;
            arr[j] = tmp;
        }

        vector<int> answer = solution(arr, n, func);
        cout << "[";
        for (int k = 0; k < answer.size(); k++)
        {
            cout << answer[k];
            if (k != answer.size())
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
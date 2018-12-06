#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);

    char str[1000000];

    cin.getline(str,sizeof(str));
    int cnt = 1;

    // for (int i = 1; i < size; i++)
    // {
    //     // cout<<str[i] - '0'<<endl;
    //     if ((str[i] - '0') == 56)
    //     {
    //         if ((str[i + 1]-'0') != 56 && (str[i-1]-'0') != 56)
    //         {
    //             cnt++;
    //         }
    //     }

    // }
    int i = 1;
    while(true)
    {
        if(str[i] == ' ')
        {
            if(str[i-1] != ' ' && str[i+1] != ' ')
            {
                cnt++;
            }
            else if(str[i-1] == ' ' && str[i+1] == ' ' )
            {
                cout<<cnt<<endl;
                return 0;
            }
        }
    }
}
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/** 단어의 개수 백준_1152 (https://www.acmicpc.net/problem/1152)
 *  ! 한단어만 나올 경우를 생각해야 함
 *  * 예외 조건 1) 처음 공백, 2) 끝 공백, 3)양쪽 공백, 4)공백만 입력, 5)공백 뒤 한글자, 6)한글자 뒤 공백, 7)입력이 없는 경우
 *  ! 시간이 너무 오래걸리는 듯 하다.
 */

// aa의 경우 1이 아닌 0이 나온다
int solution(string str, int size)
{
    int answer = 0;
    int idx = 0;

    if (str[0] == ' ') //처음이공백인경우
    {
        idx = 1;
        while (str[idx] != ' ')
        {
            idx++;
        }
        answer++;
        if (str[1] == '\0' || str[1] == ' ')
        {
            answer = 0;
            return answer;
        }
    }
    else if (str[0] != ' ') //처음이 공백이 아닌경우
    {
        idx = 0;
        while (str[idx] != ' ')
        {
            idx++;
        }
        answer++;
    }
    // idx++;
    for (int i = idx; i < size; i++)
    {
        if (str[i] == ' ' && str[i + 1] != '\0')
        {
            answer++;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    // ifstream fs("input.txt");
    // while (!fs.eof())
    // {
    // getline(fs, str);
    string str = "The Curious Case of Benjamin Button"; //6
    string str2 = " Mazatneunde Wae Teullyeoyo";        //3
    string str3 = "Teullinika Teullyeotzi ";            //2
    string str4 = "aa";                                 //1
    string str5 = " a a";                               //2
    string str6 = " aa ";                                //1
    string str7 = " ";
    // cin>>str;
    cout << solution(str3, str3.size()) << endl;
    // }
    return 0;
}
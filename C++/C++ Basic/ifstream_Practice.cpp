#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * * ifstream 및 ifstream.getline 연습
 */

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt");   // 파일 오픈
    int n, num;
    char func[100], func2[100];
    string str;
    fs.getline(func,100);   // file stream 용 getline은 char 배열을 받는다
    cout<<func[0]<<func[1]<<func[2]<<func[4]<<endl; // ? 에러가 나지 않는다??
    fs.getline(func2,100);
    cout<<func2[0]<<func2[1]<<func2[2]<<func2[3]<<func2[4]<<func2[5]<<endl;
    // fs >> n;
    // cout<<n<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     // 명령어 함수
    //     fs.getline(func, 100);
    //     cout<<func[0]<<endl;
    //     fs >> num;
    //     cout<<num<<endl;
    //     char *number = new char[num];
    //     fs.getline(number, sizeof(number), ',');
    //     for (int k = 0; k < num; k++)
    //     {
    //         cout << number[k] << endl;
    //     }
    // }

    fs.close();
    return 0;
}
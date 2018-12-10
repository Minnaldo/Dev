#include <fstream>
#include <iostream>

using namespace std;

/** CPP 파일 입출력 연습
 *
 */

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt"); //파일스트림 생성후 파일 불러오기

    if (fs.fail())
    {
        cout << "Error at file open" << endl;
        return 1;
    }

    int i = 1;
    int n;
    fs >> n;
    int *arr = new int[n];
    cout << sizeof(arr) << endl;

    while (fs >> n) //더이상 들어오는 값이 없을 때 까지 반복문 실행, 읽어들인 데이터를 한글자 씩 읽어 n에 저장
    {
        arr[i] = n;
        i++;
    }
    fs.close();

    for (int i = 1; i <= sizeof(arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
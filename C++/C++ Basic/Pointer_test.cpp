#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *arr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i * 2;
    }

    int *ptr = &arr[2];

    cout << ptr << endl;
    cout << ptr + 1 << endl;    // arr[2]의 주소값에 + 1을 한 값, 다음 주소를 가리킴, arr의 자료형은 int이므로 int의 크기만큼 늘어난다(4byte)
    cout << *ptr << endl;       // ptr이 가리키는 주소의 값을 출력
    cout << *(ptr + 1) << endl; // ptr이 가리키는 주소의 다음 주소를 가리킨다 ( arr[2+1] = arr[3])
    cout << *ptr + 1 << endl;   // ptr이 가리키는 주소의 값을 출력한 후 1을 더함

    return 0;
}
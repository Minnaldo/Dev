#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 12345;
    int *ptr = &a;

    // 암시적 형변환, suggestive type casting
    cout << typeid(65.1234f).name() << endl;
    cout << typeid(65.1234L).name() << endl;
    cout << typeid(123).name() << endl;
    cout << typeid(123l).name() << endl;
    cout << typeid(ptr).name() << endl;
    cout << typeid(*ptr).name() << endl;
    cout << typeid("a").name() << endl;
    cout << typeid('A').name() << endl;

    cout << "\n\n";
    int aa = 123;
    double bb = 123.4567;


    // 명시적 형변환, clearly type casting
    cout << typeid((int)65.1234f).name() << endl;

    // cout을 이용해 고정 소수점을 나타내는 방법
    cout << fixed;
    cout.precision(10);

    cout << typeid((double)aa).name() << "\t" << (double)aa << endl;
    printf("%3.4lf\n", (double)aa);
    cout << typeid(aa).name() << endl;

    return 0;
}
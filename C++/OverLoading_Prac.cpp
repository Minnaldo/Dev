#include <iostream>
#include <string>

/** NOTE
 *  * 오버로딩 : 함수의 이름은 같지만 파라미터(인자 값)이 다른 경우, overload : 과적하다
 *  * 오버라이딩 : 부모클래스의 함수를 자식클래스에서 재정의 하는 경우  override : 기각하다, 무시하다
 */

using namespace std;

void over(int arg)
{
    cout << "Integer function overloading  " << arg << endl;
}
void over(string arg)
{
    cout << "string function overloading  " << arg << endl;
}
void over()
{
    cout << "Call void function overloading" << endl;
}

int main(int argc, char const *argv[])
{
    over();
    over("call the string function");
    over(111);
    return 0;
}
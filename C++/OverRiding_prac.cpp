#include <iostream>

/** NOTE
 *  * 오버로딩 : 함수의 이름은 같지만 파라미터(인자 값)이 다른 경우, overload : 과적하다
 *  * 오버라이딩 : 부모클래스의 함수를 자식클래스에서 재정의 하는 경우  override : 기각하다, 무시하다
 */

using namespace std;

class AAA
{
  public:
    void overRiding()
    {
        cout << "AAA" << endl;
    }
};

class BBB : public AAA
{
  public:
    void overRiding() { cout << "BBB" << endl; }    // AAA클래스의 overRiding함수를 오버라이딩 함
};

int main(int argc, char const *argv[])
{
    AAA a;
    BBB *b; //함수 포인터?
    a.overRiding();
    b->overRiding();    // '->' 연산자는 포인터로 형태로 클래스나 함수 선언시 사용, 일반적인 인스턴스 생성시에는 '.' 연산자 사용
    return 0;
}
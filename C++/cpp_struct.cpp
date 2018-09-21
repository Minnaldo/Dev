#include <iostream>
using namespace std;

//구조체 연습

//person이름을 가진 구조체 변수 생성
struct person
{
    int age;
    char name[20];
    //구조체의 이름을 지정
}ps;

int main(int argc, char const *argv[])
{
    //ps구조체의 age속성에 접근
    ps.age = 10;
    

    cout<<ps.age<<endl;


    ps.age = 20;

    cout<<ps.age<<endl;
    return 0;
}

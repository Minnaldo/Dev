/**
 * * template 예제 코드
 * ? string & char 형에 대해서 template 사용은 어떻게?
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//Template 선언해 두 변수의 합을 리턴하는 함수
template < typename T>
T myFunc(T a, T b){
    return a + b;
}

int  main()
{
    int a= myFunc(1,3);
    // string b = myFunc("AB","CD");
    float c = myFunc(5.0, 10.0);

    printf("%d\n", a);
    // cout<<b<<endl;
    printf("%f\n", c);
}
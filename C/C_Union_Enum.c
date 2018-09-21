#include <stdio.h>
#include <stdlib.h>

union Union{
    int i_num;
    short s_num;
    char ch;
};

// case문과 같이쓰면 좋다
enum{   // 열거형 : 무언가를 식별할 때 유용
    None, Programmer, Doctor, Teacher, Salesman
    // 보통 식별자의 이름은 대문자로 함
    // 기본적으로 앞의 식별자부터 0, 1, 2, ..., n 순으로 순차적 값 가짐
    // 값을 따로 지정 가능 ex) None = 50, Programmer = 10 ...   <== integer 값만 가능
    // 새로운 값이 선언되기 전까지 1씩 증가한다.
};

int main(int argc, char const *argv[]) {

    union Union _union;

    _union.i_num = 0x12345678;

    printf("%d\n", _union.i_num );
    printf("%d\n", _union.s_num );
    printf("%d\n", _union.ch );

    return 0;
}

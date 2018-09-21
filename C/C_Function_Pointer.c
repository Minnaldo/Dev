#include <stdio.h>
#include <stdlib.h>


int function_Pointer(int num1, int num2)
{
    // printf("Plus : %d\n", num1+num2 );
    // printf("Sub : %d\n", num1-num2 );
    // printf("Mul : %d\n", num1*num2 );
    return num1 + num2;
}

int main()
{

    int a, b=0;

    int (*func_Ptr)(int, int) = function_Pointer;   //함수 포인터 선언

    printf("Please input Two values \n");
    scanf("%d", &a );
    scanf("%d", &b );
    printf("function pointer return value : %d", func_Ptr(a,b));

    return 0;
}

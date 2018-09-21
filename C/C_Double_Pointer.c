#include <stdio.h>
#include <stdlib.h>

int main() {

    int num = 0;
    int* ptr;
    int** dptr;

    ptr = &num;
    //2중포인터에 포인터의 주소를 할당
    dptr = &ptr;      // *(애스터리스크) 가 2개 이상인 포인터를 다중 포인터라 한다.

    printf("Please input Integer");
    scanf("%d", &num);

    printf("num : %d (%p)\n", num, &num);
    printf("*ptr : %d (%p)\n", *ptr, ptr);
    printf("**dptr : %d (%p)\n", **dptr, dptr );
    return 0;
}

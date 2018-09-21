#include <stdio.h>
#include <stdlib.h>

int main()
{
        int num, *adr = 0;
        int *ptr;

        printf("Plaese input the size of Array : ");
        scanf("%d", &num);

        ptr = (int*)malloc(sizeof(int)*num);    //동적 할당 배열 선언

        int i =0;

        for(i = 0 ; i<num; i++){
            adr = ptr + i;  // 포인터 변수 or 동적 할당 배열의 주소를 포인터변수 adr에 대입
            *adr = num+i;   // 대입된 주소의 값에 num+i 대입
        }

        for(i = 0; i < num; i++){
            printf("Dynamic Arr's address : %p\t Allocation values : %d\n", ptr + i/*주소값 출력*/, *(ptr+i)/*배열 안의 값 출력*/ );
        }
        printf("\n\n\n" );

        for(i = 0; i< num; i++){
            printf("Dynamic Arr's address : %p\t Allocation values : %d\n", &ptr[i]/*주소값 출력*/, ptr[i]/*배열 안의 값 출력*/ );
        }
        printf("\nThe number that User input value : %d\n", num);

        return 0;
}

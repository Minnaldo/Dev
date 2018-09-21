#include<stdio.h>
#include <stdlib.h>

int main() {

    int num = 2;
    int *ptr = &num;   //num변수의 주소가 *ptr에 저장됨
    int arr[2] = {1,4};


    printf("num : %d\n",num );
    printf("*ptr : %d\n",*ptr );    // ==> *ptr이 가지고있는 주소값(=&num, num변수의 주소값)이 가지고 있는 값을 가져옴

    printf("&num : %p\n", &num);    // ==> num에 할당된 메모리 주소값
    printf("ptr : %p\n", ptr);      // ==> 포인터 변수 ptr에 할당된 변수의 주소값

    int *arrptr = arr;

    printf("arr : %d, %d\n", arr[0], arr[1]);
    printf("*arrptr : %d\n", *arrptr);
    printf("*arrptr2 : %d\t <== *(arrptr +1)\n", *(arrptr + 1));    //포인터의 주소값에 1을 더함   ==> 배열과 연결된 포인터의 주소값에 1을 더하면 배열의 다음 칸으로 넘어감
    printf("or\n");
    printf("*arrptr2 : %d\t <== *arrptr + 1\n", *arrptr + 1);       //포인터의 값의 결과에 1을 더함 ==> 단순 덧셈 연산이 됨


    //배열 동적 할당  ==> 포인터를 이용해서 한다


    int arrsize = 0;
    printf("Please input dynamic aloocation values\n");
    scanf("%d", &arrsize);

    int *arrptr1;
    arrptr1 = (int*)malloc(sizeof(int)*arrsize);

    int fornum=0;
    for(fornum=0; fornum<arrsize; fornum++){
        printf("arrvalue : %d\n", *(arrptr1 + fornum));
        printf("arraddress : %p\n", arrptr1 + fornum);
    }

    return 0;
}


/*void pointerPrac(){
    // 자료형 *변수명; <== 포인터 선언 방법

    // *변수 <== 포인터 변수가 가지고 있는 주소에 접근하는 방법
    // &변수 <== 변수의 포인터형 반환, 변수의 주소를 나타냄
    // 또한 배열로도 접근 가능
    pb[0] = 3;
    printf("%d %d\n", a, pb[0] );   // 3, 3 출력

    //특정 자료형을 지정하지 않고 메모리 주소만 지정하는 경우도 있음 ==> void형 포인터
    //포인터 변수는 항상 4/8 바이트의 정해진 크기, 운영체제 비트수에 따라 다름
}
*/

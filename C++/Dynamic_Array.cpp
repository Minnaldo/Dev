#include <iostream>
#include <cstdio>  //C standard I/O
#include <cstring> //memset 이용하기 위한 헤더
#include <cstdlib> //malloc 이용하기 위한 헤더

using namespace std;

/** C & C++의 배열 동적할당 연습
 * *    타입 * 변수명 을 사용한다. 변수명 뒤에는 대괄호가 붙지 않으며, C는 malloc Cpp는 new 키워드를 이용한다
 * *    2차원 배열은 이중포인터 변수 선언후, 반복문을 통해 내부에 1차원 배열을 넣어준다(배열 안에 배열이 들어가있는 형태)
 */

int main(int argc, char const *argv[])
{
    //동적 할당에는 포인터 변수가 필요하다
    //1차원 배열 동적할당
    int size_Y = 0, size_X = 0;
    scanf("%d %d", &size_Y, &size_X);

    //c++ 에서는 new 키워드
    int *arrd1 = new int[size_Y];
    //  C style==> int형 포인터 변수에 malloc으로 메모리 할당, 할당 사이즈 지정 = sizeof(int) * i --> int사이즈 만큼 i개 할당
    int *cArrd1 = (int *)malloc(sizeof(int) * size_Y);

    //2차원 배열 동적 할당 C++ style
    int **arrd2 = new int *[size_Y]; //2중포인터 변수 선언
    for (int i = 0; i < size_Y; i++)
    {
        arrd2[i] = new int[size_X];
        memset(arrd2[i], 0, sizeof(int) * size_Y);  //메모리 공간 0으로 초기화
    }

    // 동적할당 2차원 배열 해제
    for (int i = 0; i < size_Y; i++)
    {
        //각 행별의 열에 할당된 값 해제
        delete[] arrd2[size_Y];
    }
    //각 행에 할당된 값 해제
    delete[] arrd2;

    //2차원 배열 동적 할당 C style
    int **carrd2 = (int **)malloc(sizeof(int) * size_Y);
    for (int i = 0; i < size_Y; i++)
    {
        carrd2[i] = (int *)malloc(sizeof(int) * size_X);
    }

    cout << "CPP Style Dynamic Array" << endl;
    for (int i; i < size_Y; i++)
    {
        for (int j; j < size_X; j++)
        {
            cout << arrd2[i][j];
        }
        cout << endl;
    }
    cout << "C Style Dynamic Array" << endl;
    for (int i; i < size_Y; i++)
    {
        for (int j; j < size_X; j++)
        {
            cout << carrd2[i][j];
        }
        cout << endl;
    }

    return 0;
}

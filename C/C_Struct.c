#include <stdio.h>
#include <stdlib.h>

//구조체만 선언된 경우 본문에서 따로 구조체변수화를 해줘야 함.
// case1
struct _Point{
    int xpos;
    int ypos;
};  // 가장 기본적인 구조체 선언문

//본문에서 바로 ponick이라는 별명으로 이 구조체를 쓰겠다.
// case2
struct Point{
    int xpos;
    int ypos;
}ponick;    // 구조체 변수 이름 = ponick

//구조체 Point2를 point2라는 별명을 부르겠다. 구조체 변수화가 된 상태가 아님
// case3
typedef struct Point2{
    int xpos;
    int ypos;
}point2;    // 구조체 변수가 아닌 typedef 이름이 point2. 즉, point2 == struct Point2를 나타냄

int main()
{
        struct _Point point;

        point2 _point2;
        // struct Point2 _point2;
        // 29,30 번줄은 같은 말이다.

        point.xpos = 5;
        point.ypos = 1;

        ponick.xpos = 2;
        ponick.ypos = 7;

        _point2.xpos = 11;
        _point2.ypos = 22;

        printf("case1 _Point : %d, %d\n", point.xpos, point.ypos);

        printf("case2 Point : %d, %d\n", ponick.xpos, ponick.ypos);

        printf("case3 Point2 : %d, %d\n", _point2.xpos, _point2.ypos );

        return 0;
}

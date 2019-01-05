#include <iostream>
#include <thread>

/**
 *  *   g++ Thread_Prac.cpp -o Thread_Prac.out --std=c++11 -pthread && ./Thread_Prac.out    ==> 컴파일 옵션
 */

using namespace std;

void counter(int id, int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf("counter[%d] : %d\n", id, i);
    }
}

int main()
{
    thread t1(counter, 1, 5);
    thread t2(counter, 2, 7);
    t1.join();
    t2.join();

    return 0;
}
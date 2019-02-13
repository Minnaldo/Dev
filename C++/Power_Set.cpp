#include <iostream>

/** 부분 집합 Power_Set (http://swlock.blogspot.com/2016/03/power-set.html)
 *  * 부분 집합을 구하는 방법
 *  NOTE need to review
 */

using namespace std;

int data[2] = {1, 7};
int flag[2];

// @param
void powerSet(int size, int depth)
{
    if (size == depth)
    {
        for (int i = 0; i < size; i++)
        {
            if (flag[i] == 1)
                cout << data[i];
        }
        cout << endl;
        return;
    }
    flag[depth] = 1;
    powerSet(n, depth + 1);
    flag[depth] = 0;
    powerSet(n, depth + 1);
}

int main(int argc, char const *argv[])
{
    powerSet(2, 0);
    return 0;
}